#include "engine/node.h"

int32_t alphaBeta(GameState* state, int depth, int a, int b, bool isMax, Move** moveOutput) {
    if (depth == 0 || state->isTerminal) {
        return getFitness(state);
    }
    MoveList* moves = listMoves(state);
    if (isMax) {
        int32_t value = -FITNESS_MAX;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, false, NULL);

            freeGameState(newState);

            if (childValue > value) {
                value = childValue;
                if (moveOutput != NULL)
                    *moveOutput = moves->moveArray[i];
            }
            if (value >= b)
                break;
            if (value > a)
                a = value;
        }
        //freeMoveList(moves);
        return value;
    }
    else {
        int32_t value = FITNESS_MAX;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, true, NULL);

            freeGameState(newState);

            if (childValue < value) {
                value = childValue;
                if (moveOutput != NULL)
                    *moveOutput = moves->moveArray[i];
            }
            if (value <= a)
                break;
            if (value < b)
                b = value;
        }
        //freeMoveList(moves);
        return value;
    }
}
