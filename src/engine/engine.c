#include "engine.h"
#include "engine/node.h"
#include "engine/gameState.h"
#include "engine/longAlgConvert.h"
#include "engine/moveSequence.h"
#include "engine/settings.h"
#include "error.h"
#include "interface/readWrite.h"
#include "pthread.h"

// Search mutex protects GameState and best Move
static pthread_mutex_t searchMutex;
static GameState* gameState;
static Move* bestMove;

static pthread_t threadId;

void initialize() {
    pthread_mutex_init(&searchMutex, NULL);
    gameState = NULL;
    bestMove = NULL;
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
    alphaBeta(gameState, 4, -FITNESS_MAX, FITNESS_MAX, gameState->turn == WHITE, &bestMove);
    pthread_mutex_unlock(&searchMutex);

    info("Search done");
    if (bestMove != NULL) {
        sendCommand("bestmove %s\n", moveToLongAlg(bestMove));
    }

    // Indicate that thread is done
    threadId = -1;
}

void startSearch() {
    if (threadId != -1) return;
    pthread_create(&threadId, NULL, &searchThread, NULL);
}

void stopSearch() {
    //if (threadId == -1) return;

}

void shutdown() {
    pthread_mutex_lock(&searchMutex);
    freeGameState(gameState);
    pthread_mutex_unlock(&searchMutex);

    exit(0);
}

char* getBestMove() {
    if (bestMove == NULL) {
        return "0000";
    }
    return moveToLongAlg(bestMove);
}