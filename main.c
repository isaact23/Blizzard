#include "main.h"

// Makefile
// Separate Node and Tree into two separate files
// Get line from game tree (w/ post processing)
// Name moves
// Get position from FEN and vice versa
// Interact with player
// Stalemate detection
// Threefold repetition
// 50-move rule

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    for (int i = 0; i < 1; i++) {
        Tree* gameTree = createGameTree(gameState);
        for (int j = 0; j < 7; j++) {
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
