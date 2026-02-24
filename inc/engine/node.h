#ifndef __NODE_H__
#define __NODE_H__

#include "engine/gameState.h"
#include "engine/move.h"
#include "engine/moveList.h"
#include "engine/moveLister.h"
#include "engine/pieces.h"
#include "engine/settings.h"
#include <stdint.h>

struct _Node {
    GameState* state;
    Move* move; // Move to get to this state
    struct _Node* children;
    int childCount;
    bool isDraw;

    int whiteWins;
    int blackWins;
    int draws;
};
typedef struct _Node Node;

int monteCarlo(Node* root);
Move* getBestMove(Node* root);
void freeTree(Node* root);

#endif
