#include "minimax.h"

// Create a game Tree with a single GameState
Tree* createGameTree(GameState* gameState) {
    Tree* tree = malloc(sizeof(Tree));
    tree -> root = createNode(NULL);
    tree -> gameStateArray = malloc(DEFAULT_GAME_STATE_ARRAY_SIZE * sizeof(GameState*));
    tree -> gameStateArray[0] = gameState;
    tree -> gameStateArraySize = DEFAULT_GAME_STATE_ARRAY_SIZE;
    tree -> depth = 0;
    return tree;
};

// Evaluate a layer of the game Tree
void evaluateGameTree(Tree* tree) {
    // Allocate more memory to gameStateArray if necessary
    if (tree -> depth >= tree -> gameStateArraySize) {
        tree -> gameStateArraySize *= 2;
        tree -> gameStateArray = realloc(tree -> gameStateArray, tree -> gameStateArraySize * sizeof(GameState*));
    }
    // Add a layer to the tree
    tree -> depth++;
    evaluateNode(tree -> root, tree -> gameStateArray[0], tree -> depth);
};

// Get the best move in the game Tree. Return NULL if none available
Move* getBestMoveFromTree(Tree* tree) {
    if (tree -> root -> bestChild == NULL) { return NULL; }
    return tree -> root -> bestChild -> move;
};

// Free dynamically allocated memory in a Tree
void freeTree(Tree* tree) {

};

// Create a node
Node* createNode(Move* move) {
    Node* node = malloc(sizeof(Node));
    node -> move = move;
    //node -> children = malloc(DEFAULT_CHILD_ARRAY_SIZE * sizeof(Node*));
    //node -> childArraySize = DEFAULT_CHILD_ARRAY_SIZE;
    node -> bestChild = NULL;
    node -> childCount = 0;
    node -> childrenCreated = 0;
    node -> fitness = 0;
    return node;
};

// Add a child to a node
void addChildToNode(Node* node, Node* child) {
    // Allocate more memory for nodes if necessary
    if (node -> childCount >= node -> childArraySize) {
        node -> childArraySize *= 2;
        node -> children = realloc(node -> children, sizeof(Node*) * node -> childArraySize);
    }
    // Append the node and increment child counter
    node -> children[node -> childCount] = child;
    node -> childCount++;
};

// Evaluate a node. Returns fitness of node.
// TODO: Alpha beta pruning AND terminal nodes.
int32_t evaluateNode(Node* node, GameState* gameState, uint16_t depth) {
    // If depth is 0, just evaluate this gameState and return.
    if (depth == 0) {
        node -> fitness = getFitness(gameState);
        return node -> fitness;
    }
    // If children don't exist, create them.
    if (node -> childrenCreated == 0) {
        MoveList* moveList = listMoves(gameState);
        node -> childCount = moveList -> moveCount;
        node -> children = malloc(moveList -> moveCount * sizeof(Node*));
        for (uint16_t i = 0; i < moveList -> moveCount; i++) {
            node -> children[i] = createNode(moveList -> moveArray[i]);
        }
        node -> childrenCreated = 1;
    }
    // Evaluate each node.
    int32_t bestFitness;
    if (gameState -> turn == WHITE) {
        bestFitness = INT32_MAX;
    } else {
        bestFitness = INT32_MIN;
    }
    for (uint16_t i = 0; i < node -> childCount; i++) {
        int32_t fitness = evaluateNode(node -> children[i], gameState + sizeof(GameState), depth - 1);
        if (gameState -> turn == WHITE) {
            if (fitness < bestFitness) {
                bestFitness = fitness;
                node -> bestChild = node -> children[i];
            }
        } else if (fitness > bestFitness) {
            bestFitness = fitness;
            node -> bestChild = node -> children[i];
        }
    }
    node -> fitness = bestFitness;
    return bestFitness;
};

// Free dynamically allocated memory in a Node
void freeNode(Node* node) {

};
