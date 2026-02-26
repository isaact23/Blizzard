
minimax(node):
    bool isMax = ...

    if node is a win for max: return ∞
    if node is a win for min: return -∞
    if node is terminal and no win: return 0

    if (node not expanded):
        Generate children nodes
        If max,
            Children nodes default as -∞
        If min,
            Children nodes default as ∞
        If there are no children, mark as terminal and return 0

        Evaluate all children nodes
        If max,
            Get max value of children.
            If max value of children > value of this node,
                Set this node's value to the children's max.
        If min,
            Get min value of children.
            If min value of children < value of this node,
                Set this node's value to the children's min.
    
    else: (node is expanded):
        If max:
            Run alphaBeta on the child of maximum fitness (with exploration, i.e. choose randomly sometimes)
            If the return value > this node's value,
                Update this node's value.
        If min:
            Run alphaBeta on the child of minimum fitness (with exploration, i.e. choose randomly sometimes)
            If the return value < this node's value,
                Update this node's value.

    return this node's value