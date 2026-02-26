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
    struct _Node** children;
    struct _Node* bestChild;
    int childCount;
    bool isTerminal;
    int32_t fitness;
};
typedef struct _Node Node;

Node* createRoot(Move* move, bool isMax);
int32_t minimax(Node* root, GameState* state);
void freeMinimaxTree(Node* root);

#endif
