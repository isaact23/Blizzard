#include "engine/chromosome.h"

Chromosome* initChromosome() {
    Chromosome* c = calloc(1, sizeof(Chromosome));
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            c->whitePawnCP[x][y] = PAWN_VALUE + (y * 10);
            c->whiteKnightCP[x][y] = KNIGHT_VALUE + (y * 10);
            c->whiteBishopCP[x][y] = BISHOP_VALUE + (y * 10);
            c->whiteRookCP[x][y] = ROOK_VALUE + (y * 10);
            c->whiteQueenCP[x][y] = QUEEN_VALUE + (y * 10);
            c->blackPawnCP[x][y] = -PAWN_VALUE - ((7 - y) * 10);
            c->blackKnightCP[x][y] = -KNIGHT_VALUE - ((7 - y) * 10);
            c->blackBishopCP[x][y] = -BISHOP_VALUE - ((7 - y) * 10);
            c->blackRookCP[x][y] = -ROOK_VALUE - ((7 - y) * 10);
            c->blackQueenCP[x][y] = -QUEEN_VALUE - ((7 - y) * 10);
        }
    }
    return c;
}