#include "main.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* gameState = openingGameState();
    MoveList* moveList = listMoves(gameState);
    for (int i = 0; i < moveList -> moveCount; i++) {
        printMove(moveList -> moveArray[i]);
    }
    printGameState(gameState);
    freeGameState(gameState);
}
