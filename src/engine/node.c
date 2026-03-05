#include "engine/node.h"

int32_t alphaBeta(GameState* state, int depth, int a, int b, Chromosome* c, Move** moveOutput) {
    bool isMax = (state->turn == WHITE);
    if (state -> outcome == OUTCOME_WHITE) return LARGE_NUM;
    if (state -> outcome == OUTCOME_BLACK) return -LARGE_NUM;
    if (state -> outcome == OUTCOME_DRAW) return 0;
    if (depth == 0) {
        return getFitness(state, c);
    }
    MoveList* moves = listMoves(state);
    Move* chosenMove = NULL;
    int32_t value;

    if (isMax) {
        value = -LARGE_NUM;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, c, NULL) - 10;

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
        value = LARGE_NUM;
        for (int i = 0; i < moves->moveCount; i++) {

            // Create the child game state
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, moves->moveArray[i]);

            // Evaluate the child tree
            int32_t childValue = alphaBeta(newState, depth - 1, a, b, c, NULL) + 10;

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
        if (chosenMove == NULL)
            *moveOutput = NULL;
        else
            *moveOutput = copyMove(chosenMove);
    }
    freeMoveList(moves);
    return value;
}
