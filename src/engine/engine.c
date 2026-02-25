#include "engine.h"
#include "engine/node.h"
#include "engine/gameState.h"
#include "engine/longAlgConvert.h"
#include "engine/moveSequence.h"
#include "engine/settings.h"
#include "error.h"
#include "interface/readWrite.h"
#include "pthread.h"

// Search mutex protects everything
static pthread_mutex_t searchMutex;
static GameState* gameState;
static Move* bestMove;

static pthread_cond_t searchDoneCond;
static bool stopFlag;

static pthread_t threadId;

void initialize() {
    pthread_mutex_init(&searchMutex, NULL);
    pthread_cond_init(&searchDoneCond, NULL);
    gameState = NULL;
    bestMove = NULL;
    stopFlag = false;
    threadId = -1;
}

void setPosition(char* fen, char** moves, int moveCount) {
    // Critical section (stop operations on GameState)
    stopSearch();
    pthread_mutex_lock(&searchMutex);

    // Erase existing game state
    if (gameState != NULL) freeGameState(gameState);

    gameState = gameStateFromFen(fen);

    // Apply all moves to the game state
    MoveSequence* moveSeq = createMoveSequence(moves, moveCount);
    MoveNode* node = moveSeq->head;
    while (node != NULL) {
        applyMoveToGameState(gameState, node -> move);
        node = node -> next;
    }
    freeMoveSequence(moveSeq);

    pthread_mutex_unlock(&searchMutex);
}

void* searchThread(void* args) {

    pthread_mutex_lock(&searchMutex);
    alphaBeta(gameState, 5, -FITNESS_MAX, FITNESS_MAX, gameState->turn == WHITE, &bestMove);
    pthread_mutex_unlock(&searchMutex);

    if (bestMove != NULL) {
        sendCommand("bestmove %s\n", moveToLongAlg(bestMove));
    } else {
        error("No move found");
    }

    pthread_mutex_lock(&searchMutex);
    if (stopFlag) {
        stopFlag = false;
        pthread_cond_signal(&searchDoneCond); // Signal that search is terminated
    }
    pthread_mutex_unlock(&searchMutex);

    // Indicate that thread is done
    threadId = -1;
}

// Initiate search thread if it isn't already running.
void startSearch() {
    pthread_mutex_lock(&searchMutex);
    if (threadId == -1) {
        pthread_create(&threadId, NULL, &searchThread, NULL);
    }
    pthread_mutex_unlock(&searchMutex);
}

// Signal search thread to stop, and wait until it has fully stopped.
void stopSearch() {
    pthread_mutex_lock(&searchMutex);
    if (threadId == -1) {
        pthread_mutex_unlock(&searchMutex);
        return;
    }
    stopFlag = true;

    // Wait until searching thread signals that it has stopped
    while (stopFlag == true) {
        pthread_cond_wait(&searchDoneCond, &searchMutex);
    }

    pthread_mutex_unlock(&searchMutex);
}

// Clean up memory and stop Blizzard program.
void shutdown() {
    pthread_mutex_lock(&searchMutex);
    if (gameState != NULL) {
        freeGameState(gameState);
    }
    pthread_mutex_unlock(&searchMutex);

    exit(0);
}

char* getBestMove() {
    if (bestMove == NULL) {
        return "0000";
    }
    return moveToLongAlg(bestMove);
}