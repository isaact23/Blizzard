#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    printGameState(gameState);
    printMoves(moveList);
    freeMoveList(moveList);
    freeGameState(gameState);
}
