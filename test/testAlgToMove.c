#include "test.h"
#include "engine/longAlgConvert.h"
#include "engine/move.h"

void testAlgToMove() {
    printf("Testing long algebra to move conversion\n");
    Move* move1 = longAlgToMove("e2e4");
    assert(move1->from_x == 4);
    assert(move1->from_y == 1);
    assert(move1->to_x == 4);
    assert(move1->to_y == 3);
    printf("Done testing long algebra to move conversion\n");
}