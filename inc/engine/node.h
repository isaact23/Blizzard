#ifndef __NODE_H__
#define __NODE_H__

#include "engine/chromosome.h"
#include "engine/gameState.h"
#include "engine/moveList.h"
#include "engine/moveLister.h"
#include "engine/settings.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define LARGE_NUM 100000000

struct _Node {
    Move* move; // Move to get to this state
    struct _Node** children;
    struct _Node* bestChild;
    int childCount;
    bool isTerminal;
    int32_t fitness;
};
typedef struct _Node Node;

int32_t alphaBeta(GameState* state, int depth, int a, int b, Chromosome* c, Move** moveOutput);

#endif
