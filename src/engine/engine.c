#include "engine.h"
#include "engine/gameState.h"

static GameState* gameState;

void initialize() {
    gameState = NULL;
}

void startPosition() {
    // Erase existing game state
    if (gameState != NULL) freeGameState(gameState);

    gameState = openingGameState();
}

void setPosition(char* fen, char** moves, int moveCount) {
    // Erase existing game state
    if (gameState != NULL) freeGameState(gameState);

    gameState = gameStateFromFen(fen);

}

void startSearch() {

}

void stopSearch() {

}

Move* getBestMove() {

}