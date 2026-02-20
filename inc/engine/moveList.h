#ifndef __MOVE_LIST_H__
#define __MOVE_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "move.h"

#define DEFAULT_MOVELIST_SIZE 10

// Unordered structure that stores multiple moves
struct _MoveList {
    Move** moveArray;
    uint16_t moveCount;
    uint16_t arraySize;
};
typedef struct _MoveList MoveList;

// Print all moves in a MoveList
void printMoves(MoveList* moveList);

// Get empty MoveList
MoveList* createMoveList();

// Add a Move to a MoveList
void addMove(MoveList* moveList, uint8_t from_x, uint8_t from_y, uint8_t to_x, uint8_t to_y, uint8_t promotion);

// Free memory in a MoveList
void freeMoveList(MoveList* moveList);

#endif
