#include "main.h"

// Computer vs computer
void cvc() {
    GameState* gameState = openingGameState();
    printGameState(gameState);
    bool isWhite = true;
    while (!gameState->isTerminal) {
        Move move;
        alphaBeta(gameState, 6, INT32_MIN, INT32_MAX, isWhite, &move);
        applyMoveToGameState(gameState, &move);
        printGameState(gameState);
        isWhite = !isWhite;
    }
    freeGameState(gameState);
}

// Player (white) vs computer (black)
void pvc() {
    GameState* gameState = openingGameState();
    printGameState(gameState);
    while (!gameState->isTerminal) {

        // Player
        MoveList* moves = listMoves(gameState);
        printMoves(moves);
        printf("Enter move number: ");
        int moveNo;
        scanf("%d", &moveNo);
        applyMoveToGameState(gameState, moves->moveArray[moveNo - 1]);
        printGameState(gameState);

        // Computer
        Move move;
        alphaBeta(gameState, 6, INT32_MIN, INT32_MAX, false, &move);
        applyMoveToGameState(gameState, &move);
        printGameState(gameState);
    }
    freeGameState(gameState);
}

// Run the chess program.
int main() {
    printHeader();
    pvc();
}
