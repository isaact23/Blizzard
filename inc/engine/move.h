#ifndef __MOVE_H__
#define __MOVE_H__

// Store data for a move
struct _Move {
    uint8_t from_x;
    uint8_t from_y;
    uint8_t to_x;
    uint8_t to_y;

    uint8_t promotion; /* Use macros from pieces.h (QUEEN, BISHOP, ROOK, KNIGHT)
        /* For no promotion, use 0 or EMPTY */
};
typedef struct _Move Move;

// Print a move
void printMove(Move* move);

#endif