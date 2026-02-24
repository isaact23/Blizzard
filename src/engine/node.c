#include "engine/node.h"

int monteCarlo(Node* root) {
    if (root == NULL) return 0;
    if (root -> isDraw) return OUTCOME_DRAW;

    int outcome = root -> gameState -> winner;
    if (outcome != OUTCOME_EMPTY) return outcome;

    // Expand the node if it hasn't already been expanded
    if (root -> children == NULL) {
        MoveList* list = listMoves(root -> state);
        if (list -> moveCount == 0) {
            freeMoveList(list);
            root -> isDraw = true;
            return OUTCOME_DRAW;
        }

        // Allocate memory for Move array
        root -> children = malloc(sizeof(Node*) * (list -> moveCount));
        root -> childCount = list -> moveCount;

        // Create child nodes
        for (int i = 0; i < list -> moveCount; i++) {
            Node* newNode = malloc(sizeof(Node));

            // Fetch the move and create an updated GameState
            Move* move = list -> moveArray[i];
            newNode -> move = move;
            GameState* newState = copyGameState(root -> state);
            applyMoveToGameState(newState, move);
            newNode -> state = newState;

            newNode -> children = NULL;
            newNode -> childCount = 0;
            newNode -> isDraw = false;

            newNode -> whiteWins = 0;
            newNode -> blackWins = 0;
            newNode -> draws = 0;
        }
    }

    // Choose a child node to evaluate
    
}

Move* getBestMove(Node* root) {
    if (root == NULL) return NULL;
}

void freeTree(Node* root) {

}
