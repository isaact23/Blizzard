#include "engine/moveSequence.h"

// Convert a list of long algebra notation moves to a MoveSequence for engine use.
MoveSequence* createMoveSequence(char** moves, int moveCount) {
    MoveNode* head = NULL;
    MoveNode* tail = NULL;

    for (int i = 0; i < moveCount; i++) {

        // Convert long algebra 
        Move* move = longAlgToMove(moves[i]);
        MoveNode* newNode = malloc(sizeof(MoveNode));
        newNode -> move = move;
        newNode -> next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    // Wrap linked list in MoveSequence struct
    MoveSequence* seq = malloc(sizeof(MoveSequence));
    seq -> head = head;
    return seq;
}

// Print moves, in order, in a MoveSequence
void printMoveSequence(MoveSequence* sequence) {
    MoveNode* cur = sequence -> head;
    while (cur != NULL) {
        printMove(cur -> move);
        cur = cur -> next;
    }
}

// Free all memory from a MoveSequence.
void freeMoveSequence(MoveSequence* sequence) {
    MoveNode* cur = sequence -> head;
    free(sequence);

    while (cur != NULL) {
        MoveNode* next = cur -> next;
        free(cur -> move);
        free(cur);
        cur = next;
    }
}