#include "engine/move.h"

// Print a move
void printMove(Move* move) {
    printf("From (%d, %d) to (%d, %d) promotion %d\n",
        move -> from_x, move -> from_y, move -> to_x, move -> to_y, move -> promotion);
};
