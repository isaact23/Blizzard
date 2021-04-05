#include "minimax.h"

// Create a game Tree with a single GameState
Tree* createGameTree(GameState* gameState) {
    Tree* tree = malloc(sizeof(Tree));
    Node* root = createNode(NULL);
    tree -> root = root;
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
    Node* root = tree -> root;
    uint16_t depth = tree -> depth;
    int32_t result = evaluateNode(root, tree -> gameStateArray, 0, depth);
};

// Get the best move in the game Tree. Return NULL if none available
Move* getBestMove(Tree* tree) {
    if (tree -> root -> bestChild == NULL) { return NULL; }
    return tree -> root -> bestChild -> move;
};

// Free dynamically allocated memory in a Tree, EXCEPT for the first GameState.
void freeTree(Tree* tree) {
    freeNode(tree -> root);
    for (uint16_t i = 1; i < tree -> gameStateArraySize; i++) {
        freeGameState(tree -> gameStateArray[i]);
    }
    free(tree -> gameStateArray);
    free(tree);
};

// Create a node
Node* createNode(Move* move) {
    Node* node = malloc(sizeof(Node));
    node -> move = move;
    node -> children = malloc(DEFAULT_CHILD_ARRAY_SIZE * sizeof(Node*));
    node -> childArraySize = DEFAULT_CHILD_ARRAY_SIZE;
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
int32_t evaluateNode(Node* node, GameState** gameStateArray, uint16_t layer, uint16_t depth) {
    // Get the gameState at this node's layer
    GameState* gameState = gameStateArray[layer];

    // Apply this node's move to the gameState.
    if (node -> move != NULL) {
        applyMoveToGameState(gameState, node -> move);
    }

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
    // Set bestFitness to worst case scenario.
    int32_t bestFitness;
    if (gameState -> turn == WHITE) {
        bestFitness = INT32_MIN;
    } else {
        bestFitness = INT32_MAX;
    }
    // Evaluate each child node.
    for (uint16_t i = 0; i < node -> childCount; i++) {
        // Copy this node's gameState to the next layer.
        //*((&gameState) + sizeof(GameState*)) = copyGameState(gameState);
        gameStateArray[layer + 1] = copyGameState(gameState);

        // Evaluate child node.
        //int32_t fitness = evaluateNode(node -> children[i], *((&gameState) + sizeof(GameState*)), depth - 1);
        int32_t fitness = evaluateNode(node -> children[i], gameStateArray, layer + 1, depth - 1);

        // Determine if the child node is the strongest node evaluated so far.
        if (gameState -> turn == WHITE) {
            if (fitness > bestFitness) {
                bestFitness = fitness;
                node -> bestChild = node -> children[i];
            }
        } else if (fitness < bestFitness) {
            bestFitness = fitness;
            node -> bestChild = node -> children[i];
        }
    }
    node -> fitness = bestFitness;
    return bestFitness;
};

// Free dynamically allocated memory in a Node
void freeNode(Node* node) {
    if (node != NULL) {
        free(node -> move);
        for (uint16_t i = 0; i < node -> childCount; i++) {
            free(node -> children[i]);
        }
        // No need to free bestChild because it's included in the above array.
        free(node);
    }
};
