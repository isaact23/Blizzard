#ifndef __MOVE_H__
#define __MOVE_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

// Just haphazardly putting an include statement after the Move struct nothing to see here
// (longAlgConvert and move cross-reference; this ordering is needed for compilation)
#include "engine/longAlgConvert.h"

// Duplicate a move
Move* copyMove(Move* move);

// Print a move
void printMove(Move* move);

#endif