#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    Tree* gameTree = createGameTree(gameState);
    evaluateGameTree(gameTree);

    printGameState(gameState);

    // Free dynamically allocated memory
    freeGameState(gameState);
    freeTree(gameTree);
}
