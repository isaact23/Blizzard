#ifndef __NODE_H__
#define __NODE_H__

#include "engine/gameState.h"
#include "engine/moveList.h"
#include "engine/moveLister.h"
#include "engine/settings.h"
#include <stdint.h>
#include <stdlib.h>

struct _Node {
    Move* move; // Move to get to this state
    int fitness;
    int child_count;
    struct _Node* children;
};
typedef struct _Node Node;

int32_t alphaBeta(GameState* state, int depth, int a, int b, bool isMax, Move** moveOutput);

#endif
