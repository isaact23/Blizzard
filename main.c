#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    printGameState(gameState);
    Tree* gameTree = createGameTree(gameState);
    evaluateGameTree(gameTree);

    // Free dynamically allocated memory.
    // Since gameState is part of the tree, gameState is also freed.
    freeTree(gameTree);
}
