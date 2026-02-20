#ifndef __MOVE_SEQUENCE_H__
#define __MOVE_SEQUENCE_H__

#include "engine/move.h"
#include "engine/longAlgConvert.h"
#include "engine/pieces.h"
#include <stdlib.h>

struct _moveNode {
    Move* move;
    struct _moveNode* next;
};
typedef struct _moveNode MoveNode;

struct _moveSequence {
    MoveNode* head;
};
typedef struct _moveSequence MoveSequence;

// Convert a list of long algebra notation moves to a MoveSequence for engine use.
MoveSequence* createMoveSequence(char** moves, int moveCount);

// Print moves, in order, in a MoveSequence
void printMoveSequence(MoveSequence* sequence);

// Free all memory from a MoveSequence.
void freeMoveSequence(MoveSequence* sequence);

#endif
