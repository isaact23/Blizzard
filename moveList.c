#include "moveList.h"

// Get empty MoveList
MoveList* emptyMoveList() {
    MoveList* moveList = malloc(sizeof(MoveList));
    if (moveList == NULL) { return NULL; }
    moveList -> moveArray = malloc(DEFAULT_MOVELIST_SIZE * sizeof(Move*));
    if (moveList -> moveArray == NULL) { return NULL; }
    moveList -> arraySize = DEFAULT_MOVELIST_SIZE;
    moveList -> moveCount = 0;
    return moveList;
};

// Add a Move to a MoveList
void addMove(MoveList* moveList, Move* move) {
    // Allocate more memory if needed
    if (moveList -> moveCount >= moveList -> arraySize) {
        moveList -> arraySize *= 2;
        moveList -> moveArray = realloc(moveList -> moveArray, moveList -> arraySize * sizeof(Move*));
    }
    // Add move to array
    moveList -> moveArray[moveList -> moveCount] = move;

    // Increment move counter
    moveList -> moveCount++;
};

// Free memory in a MoveList
void freeMoveList(MoveList* moveList) {
    // Free each Move
    for (int i = 0; i < moveList -> moveCount; i++) {
        free(moveList -> moveArray[i]);
    }
    // Free array
    free(moveList -> moveArray);
};
