#include "engine/move.h"

// Print a move
void printMove(Move* move) {
    char* moveStr = moveToLongAlg(move);
    printf("%s\n", moveStr);
    free(moveStr);
};
