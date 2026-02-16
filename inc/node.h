#ifndef NODE_H
#define NODE_H

struct _Node {
    Move* move; // Move to get to this state
    int fitness;
    int child_count;
    _Node* children;
}
typedef struct _Node Node;

Move* getBestMove(GameState* state, int depth);

#endif
