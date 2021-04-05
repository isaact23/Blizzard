#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    for (int i = 0; i < 10; i++) {
        Tree* gameTree = createGameTree(gameState);
        for (int j = 0; j < 4; j++) {
            evaluateGameTree(gameTree);
        }
        Move* bestMove = getBestMove(gameTree);
        applyMoveToGameState(gameState, bestMove);
        freeTree(gameTree);
    }
    printGameState(gameState);

    // Free dynamically allocated memory.
    freeGameState(gameState);
}
