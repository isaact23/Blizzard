#include "engine/move.h"

// Duplicate a move
Move* copyMove(Move* move) {
    Move* newMove = malloc(sizeof(Move));
    newMove -> from_x = move -> from_x;
    newMove -> from_y = move -> from_y;
    newMove -> to_x = move -> to_x;
    newMove -> to_y = move -> to_y;
    newMove -> promotion = move -> promotion;
    return newMove;
}

// Print a move
void printMove(Move* move) {
    char* moveStr = moveToLongAlg(move);
    printf("%s\n", moveStr);
    free(moveStr);
};
