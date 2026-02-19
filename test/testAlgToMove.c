#include "test.h"
#include "longAlgConvert.h"
#include ""

void testAlgToMove() {
    printf("Testing long algebra to move conversion\n");
    Move* move1 = longAlgToMove("e2e4");
    assert(move1->from_x == 4);
    assert(move1->from_y == 1);
    assert(move1->to_x == 4);
    assert(move1->to_y == 3);
}