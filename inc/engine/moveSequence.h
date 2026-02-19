#ifndef __MOVE_SEQUENCE_H__
#define __MOVE_SEQUENCE_H__

#include "move.h"
#include "pieces.h"
#include <stdlib.h>

struct _moveNode {
    Move* move;
    struct _moveNode* next;
};
typedef struct _moveNode MoveNode;

struct _moveSequence {
    MoveNode* node;
};
typedef struct _moveSequence MoveSequence;


MoveSequence* createMoveSequence(char** moves, int moveCount);

#endif
