#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    MoveList* moveList = listMoves(gameState);
    applyMoveToGameState(gameState, moveList -> moveArray[11]);
    freeMoveList(moveList);
    MoveList* moveList2 = listMoves(gameState);
    applyMoveToGameState(gameState, moveList2 -> moveArray[11]);
    printGameState(gameState);
    freeMoveList(moveList2);
    freeGameState(gameState);
}
