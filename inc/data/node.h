#ifndef NODE_H
#define NODE_H

// Stores a single chess move and descendants.
typedef struct _Node Node;
struct _Node {
    Move* move;
    Node** children;
    Node* bestChild;
    uint16_t childArraySize;
    uint16_t childCount;
    uint8_t childrenCreated;
    int32_t fitness;
    int32_t alpha;
    int32_t beta;
};

// Create a node
Node* createNode(Move* move);

#endif
