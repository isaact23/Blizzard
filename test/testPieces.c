#include <stdio.h>
#include "test.h"
#include "engine/pieces.h"

void testPieces() {
    printf("Testing pieces\n");
    printf("%d\n", EMPTY);
    printf("%d\n", WK);
    printf("%d\n", WQ);
    printf("%d\n", WB);
    printf("%d\n", WN);
    printf("%d\n", WR);
    printf("%d\n", WP);
    printf("%d\n", BK);
    printf("%d\n", BQ);
    printf("%d\n", BB);
    printf("%d\n", BN);
    printf("%d\n", BR);
    printf("%d\n", BP);
    assert(getPieceColor(EMPTY) == 0);
    assert(getPieceColor(WK) == WHITE);
    assert(getPieceColor(WQ) == WHITE);
    assert(getPieceColor(WB) == WHITE);
    assert(getPieceColor(WN) == WHITE);
    assert(getPieceColor(WR) == WHITE);
    assert(getPieceColor(WP) == WHITE);
    assert(getPieceColor(BK) == BLACK);
    assert(getPieceColor(BQ) == BLACK);
    assert(getPieceColor(BB) == BLACK);
    assert(getPieceColor(BN) == BLACK);
    assert(getPieceColor(BR) == BLACK);
    assert(getPieceColor(BP) == BLACK);
    printf("Done testing pieces\n");
}
