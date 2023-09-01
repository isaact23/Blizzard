#include "tree.h"

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