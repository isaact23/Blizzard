#ifndef __NODE_H__
#define __NODE_H__

#include "gameState.h"
#include "moveList.h"
#include "moveLister.h"
#include <stdint.h>

struct _Node {
    Move* move; // Move to get to this state
    int fitness;
    int child_count;
    struct _Node* children;
};
typedef struct _Node Node;

int32_t alphaBeta(GameState* state, int depth, int a, int b, bool isMax, Move* moveOutput);

#endif
