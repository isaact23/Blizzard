#include "engine/node.h"

int32_t alphaBeta(Node* root, GameState* state) {
    if (state -> outcome == OUTCOME_WHITE) return INT32_MAX;
    if (state -> outcome == OUTCOME_BLACK) return INT32_MIN;
    if (state -> outcome == OUTCOME_DRAW) return 0;

    // Expansion
    if (root -> children == NULL) {
        
    }
}
