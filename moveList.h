#ifndef MOVELIST_H
#define MOVELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEFAULT_MOVELIST_SIZE 10

// Store data for a move
struct _Move {
    uint8_t from_x;
    uint8_t from_y;
    uint8_t to_x;
    uint8_t to_y;
    uint8_t promotion;
};
typedef struct _Move Move;

// Structure that stores multiple moves
struct _MoveList {
    Move** moveArray;
    uint16_t moveCount;
    uint16_t arraySize;
};
typedef struct _MoveList MoveList;

// Print a move
void printMove(Move* move);

// Print all moves in a MoveList
void printMoves(MoveList* moveList);

// Get empty MoveList
MoveList* emptyMoveList();

// Add a Move to a MoveList
void addMove(MoveList* moveList, uint8_t from_x, uint8_t from_y, uint8_t to_x, uint8_t to_y, uint8_t promotion);

// Free memory in a MoveList
void freeMoveList(MoveList* moveList);

#endif
