#ifndef MINIMAX_H
#define MINIMAX_H

#define DEFAULT_DEPTH 2
#define DEFAULT_CHILD_ARRAY_SIZE 10

#include <stdint.h>
#include "moveList.h"
#include "gameState.h"

// Stores a single chess move and descendants.
typedef struct _Node Node;
struct _Node {
    Move* move;
    Node** children;
    uint16_t childArraySize
    uint16_t childCount;
    int32_t fitness;
    uint8_t childrenEvaluated; // 1 if children evaluated, 0 if not
};

// Stores the evaluated game tree.
typedef struct _Tree Tree;
struct _Tree {
    Node* root;
    GameState** gameStateArray;
    uint16_t depth;
};

// Create a game Tree with a single GameState
Tree* createGameTree(GameState* gameState);

// Evaluate a layer of the game Tree
void evaluateGameTree(Tree* tree);

// Get the best move in the game Tree
Move* getBestMove(Tree* tree);

// Create a node
Node* createNode(Move* move);

// Add a child to a node
void addChildToNode(Node* node, Node* child);

// Evaluate a node
void evaluateNode(Node* node, GameState* gameState, uint16_t depth);

// Free dynamically allocated memory in a Tree
void freeTree(Tree* tree);

// Free dynamically allocated memory in a Node
void freeNode(Node* node);

#endif
