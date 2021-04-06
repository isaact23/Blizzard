#ifndef MINIMAX_H
#define MINIMAX_H

#include <stdint.h>
#include <stdio.h>
#include "moveList.h"
#include "moveLister.h"
#include "gameState.h"
#include "pieces.h"

#define DEFAULT_GAME_STATE_ARRAY_SIZE 2
#define DEFAULT_CHILD_ARRAY_SIZE 2

// Stores a single chess move and descendants.
typedef struct _Node Node;
struct _Node {
    Move* move;
    Node** children;
    Node* bestChild;
    uint16_t childArraySize;
    uint16_t childCount;
    uint8_t childrenCreated;
    int32_t fitness;
    int32_t alpha;
    int32_t beta;
};

// Stores the evaluated game tree.
typedef struct _Tree Tree;
struct _Tree {
    Node* root;
    GameState** gameStateArray;
    uint16_t gameStateArraySize;
    uint16_t depth;
};

// Create a game Tree with a single GameState
Tree* createGameTree(GameState* gameState);

// Evaluate a layer of the game Tree
void evaluateGameTree(Tree* tree);

// Get the best move in the game Tree. Return NULL if none available
Move* getBestMove(Tree* tree);

// Free dynamically allocated memory in a Tree
void freeTree(Tree* tree);

// Create a node
Node* createNode(Move* move);

// Add a child to a node
void addChildToNode(Node* node, Node* child);

// Evaluate a node. Returns fitness of node
int32_t evaluateNode(Node* node, GameState** gameStateArray, uint16_t layer, uint16_t depth, int32_t alpha, int32_t beta);

// Free dynamically allocated memory in a Node
void freeNode(Node* node);

#endif
