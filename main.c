#include "main.h"

// Evaluate game tree without seg faults
// Get line from game tree (w/ post processing)
// Name moves
// Get position from FEN and vice versa
// Interact with player

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    for (int i = 0; i < 30; i++) {
        Tree* gameTree = createGameTree(gameState);
        for (int j = 0; j < 4; j++) {
            evaluateGameTree(gameTree);
        }
        Move* bestMove = getBestMove(gameTree);
        applyMoveToGameState(gameState, bestMove);
        freeTree(gameTree);
        printGameState(gameState);
    }

    // Free dynamically allocated memory.
    freeGameState(gameState);
}
