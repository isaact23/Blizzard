#ifndef __CHROMOSOME_H__
#define __CHROMOSOME_H__

#include <stdint.h>
#include <stdlib.h>
#include "engine/pieces.h"

struct _Chromosome {
    // 768 numbers
    int32_t whitePawnCP[8][8];
    int32_t whiteKnightCP[8][8];
    int32_t whiteBishopCP[8][8];
    int32_t whiteRookCP[8][8];
    int32_t whiteQueenCP[8][8];
    int32_t whiteKingCP[8][8];
    int32_t blackPawnCP[8][8];
    int32_t blackKnightCP[8][8];
    int32_t blackBishopCP[8][8];
    int32_t blackRookCP[8][8];
    int32_t blackQueenCP[8][8];
    int32_t blackKingCP[8][8];
};
typedef struct _Chromosome Chromosome;

Chromosome* initChromosome();

#endif
