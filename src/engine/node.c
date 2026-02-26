#include "engine/node.h"

Node* createRoot(Move* move, bool isMax) {
    Node* node = malloc(sizeof(Node));
    node -> move = move;
    node -> bestChild = NULL;
    node -> children = NULL;
    node -> childCount = 0;
    node -> isTerminal = false;
    if (isMax) {
        node -> fitness = INT32_MIN;
    } else {
        node -> fitness = INT32_MAX;
    }
    return node;
}

int32_t minimax(Node* root, GameState* state) {
    if (root -> isTerminal) return 0;
    if (state -> outcome == OUTCOME_WHITE) return INT32_MAX;
    if (state -> outcome == OUTCOME_BLACK) return INT32_MIN;
    if (state -> outcome == OUTCOME_DRAW) return 0;

    bool isMax = ((state -> turn) == WHITE);

    // Expansion
    if (root -> children == NULL) {
        MoveList* list = listMoves(state);
        if (list -> moveCount == 0) {
            freeMoveList(list);
            root -> isTerminal = true;
            return 0;
        }

        // Allocate memory for Move array
        root -> children = malloc(sizeof(Node*) * (list -> moveCount));
        root -> childCount = list -> moveCount;

        int32_t bestFitness;
        Node* bestChild = NULL;
        if (isMax) {
            bestFitness = INT32_MIN;
        } else {
            bestFitness = INT32_MAX;
        }

        // Create child nodes
        for (int i = 0; i < list -> moveCount; i++) {
            Node* newNode = malloc(sizeof(Node));

            // Fetch the move and create an updated GameState
            Move* move = list -> moveArray[i];
            newNode -> move = move;
            GameState* newState = copyGameState(state);
            applyMoveToGameState(newState, move);

            int32_t fitness = getFitness(newState);

            newNode -> bestChild = NULL;
            newNode -> children = NULL;
            newNode -> childCount = 0;
            newNode -> isTerminal = false;
            newNode -> fitness = fitness;

            freeGameState(newState);

            // Keep track of the best child
            if ((isMax && (fitness > bestFitness)) ||
                ((!isMax) && (fitness < bestFitness)))
            {
                bestFitness = fitness;
                bestChild = newNode;
            }

            root -> children[i] = newNode;
        }

        root -> fitness = bestFitness;
        root -> bestChild = bestChild;
    }

    // Traversal
    else {
        GameState* newState = copyGameState(state);
        Node* childNode = NULL;

        // Select best node for exploration
        if (random() % 5 == 0) {
            childNode = root -> bestChild;
        }
        // Select random node for exploration
        else {
            childNode = root -> children[random() % (root -> childCount)];
        }

        if (childNode -> move != NULL) {
            applyMoveToGameState(newState, childNode -> move);
        }

        int32_t newFitness = minimax(childNode, newState);

        // Update best fitness of parent node
        // TODO: Only do if the childNode's fitness was the best but became worse
        int32_t bestFitness;
        Node* bestChild = NULL;
        if (isMax) {
            bestFitness = INT32_MIN;
        } else {
            bestFitness = INT32_MAX;
        }
        for (int i = 0; i < root -> childCount; i++) {
            Node* child = root -> children[i];
            int32_t fitness = child -> fitness;
            if ((isMax && (fitness > bestFitness)) ||
                ((!isMax) && (fitness < bestFitness)))
            {
                bestFitness = fitness;
                bestChild = child;
            }
        }
        root -> fitness = bestFitness;
        root -> bestChild = bestChild;

        freeGameState(newState);
    }

    return root -> fitness;
}

void printMinimaxTree(Node* root, int depth) {
    char* moveStr = NULL;
    if (root -> move != NULL) {
        moveStr = moveToLongAlg(root -> move);
    }
    for (int i = 0; i < root -> childCount; i++) {
        printMinimaxTree(root -> children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    if (moveStr != NULL) {
        printf("%s\n", moveStr);
        free(moveStr);
    }
    else {
        printf("\n");
    }
}

void freeMinimaxTree(Node* root) {
    for (int i = 0; i < root -> childCount; i++) {
        freeMinimaxTree(root -> children[i]);
    }
    free(root -> children);
    free(root);
}
