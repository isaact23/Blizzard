#include "engine/node.h"

int32_t alphaBeta(GameState* state, int depth, int a, int b, bool isMax, Move** moveOutput) {
    if (state -> winner == WHITE) {
        return FITNESS_MAX;
    }
    if (state -> winner == BLACK) {
        return -FITNESS_MAX;
    }
    if (depth == 0) {
        return getFitness(state);
    }
    MoveList* moves = listMoves(state);
    Move* chosenMove = NULL;
    int32_t value;

    if (isMax) {
        value = -FITNESS_MAX;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, false, NULL);

            freeGameState(newState);

            if (childValue > value) {
                value = childValue;
                chosenMove = moves->moveArray[i];
            }
            if (value >= b)
                break;
            if (value > a)
                a = value;
        }
    }
    else {
        value = FITNESS_MAX;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, true, NULL);

            freeGameState(newState);

            if (childValue < value) {
                value = childValue;
                chosenMove = moves->moveArray[i];
            }
            if (value <= a)
                break;
            if (value < b)
                b = value;
        }
    }

    if (moveOutput != NULL) {
        
        // If no move was chosen and moves are available, choose randomly.
        //if (chosenMove == NULL && moves -> moveCount > 0) {
        //    chosenMove = moves -> moveArray[random() % (moves -> moveCount)];
        //}

        *moveOutput = chosenMove;
    }
    return value;
}
