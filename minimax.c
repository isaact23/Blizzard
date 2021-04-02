#include "minimax.h"

// Create a game Tree with a single GameState
Tree* createGameTree(GameState* gameState) {
    Tree* tree = malloc(sizeof(Tree));
    tree -> root = createNode(NULL);
    tree -> gameStateArray = malloc(DEFAULT_DEPTH * sizeof(GameState));
    tree -> gameStateArray[0] = gameState;
    tree -> depth = DEFAULT_DEPTH;
    return tree;
};

// Evaluate a layer of the game Tree
void evaluateGameTree(Tree* tree) {

};

// Get the best move in the game Tree
Move* getBestMove(Tree* tree) {
    
};

// Create a node
Node* createNode(Move* move) {
    Node* node = malloc(sizeof(Node));
    node -> move = move;
    node -> children = malloc(DEFAULT_CHILD_ARRAY_SIZE * sizeof(Node*));
    node -> childArraySize = DEFAULT_CHILD_ARRAY_SIZE;
    node -> childCount = 0;
    node -> fitness = 0;
    return node;
};

// Add a child to a node
void addChildToNode(Node* node, Node* child) {
    // Allocate more memory for nodes if necessary
    if (node -> childCount >= node -> childArraySize) {
        node -> childArraySize *= 2;
        node -> childArray = realloc(node -> childArray, sizeof(Node*) * node -> childArraySize);
    }
    // Append the node and increment child counter
    node -> childArray[node -> childCount] = child;
    node -> childCount++;
};

// Evaluate a node
void evaluateNode(Node* node, uint16_t depth) {

};

// Free dynamically allocated memory in a Tree
void freeTree(Tree* tree) {

};

// Free dynamically allocated memory in a Node
void freeNode(Node* node) {

};
