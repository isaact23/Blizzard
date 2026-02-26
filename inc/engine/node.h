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
    struct _Node* children;
    int child_count;
    int32_t fitness;
    int32_t alpha;
    int32_t beta;
};
typedef struct _Node Node;

int32_t alphaBeta(Node* root, GameState* state);

#endif
