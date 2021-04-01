#ifndef MINIMAX_H
#define MINIMAX_H

#include <stdint.h>

// Stores the evaluated game tree.
struct _Tree {
    Node* root;
    GameState** gameStateArray;
    uint16_t gameStateArraySize;
}
typedef struct _Tree Tree;

// Stores a single chess move and descendants.
struct _Node {
    Move* move;
    Node** children;
    uint16_t childCount;
    int32_t fitness;
}
typedef struct _Node Node;

// Create a game Tree with a single GameState
Tree* blankGameTree(GameState* gameState);

// Evaluate a layer of the game Tree
void evaluateGameTree(Tree* tree);

// Get the best move in the game Tree
Move* getBestMove(Tree* tree);

#endif
