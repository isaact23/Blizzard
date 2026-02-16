#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    printGameState(gameState);
    MoveList* moveList = listMoves(gameState);
    printMoves(moveList);
    freeMoveList(moveList);
    freeGameState(gameState);
}
