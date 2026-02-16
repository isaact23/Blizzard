#include "moveList.h"

// Print a move
void printMove(Move* move) {
    printf("From (%d, %d) to (%d, %d) promotion %d\n",
        move -> from_x, move -> from_y, move -> to_x, move -> to_y, move -> promotion);
};

// Print all moves in a MoveList
void printMoves(MoveList* moveList) {
    for (int i = 0; i < moveList -> moveCount; i++) {
        printMove(moveList -> moveArray[i]);
    }
}

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
void addMove(MoveList* moveList, uint8_t from_x, uint8_t from_y, uint8_t to_x, uint8_t to_y, uint8_t promotion) {
    Move* move = malloc(sizeof(Move));
    move -> from_x = from_x;
    move -> from_y = from_y;
    move -> to_x = to_x;
    move -> to_y = to_y;
    move -> promotion = promotion;

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
    // Free remaining memory
    free(moveList -> moveArray);
    free(moveList);
};
