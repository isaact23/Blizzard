#ifndef __LONG_ALT_CONVERT_H__
#define __LONG_ALT_CONVERT_H__

#include "engine/move.h"
#include "engine/pieces.h"
#include "error.h"
#include <stdlib.h>

int fileCharToNum(char file);
int rankCharToNum(char rank);
char numToFileChar(int file);
char numToRankChar(int rank);

/* Convert internal move representation to long algebraic notation. */
char* moveToLongAlg(Move* move);

/* Convert long algebraic notation to the internal move representation. */
Move* longAlgToMove(char* moveStr);

#endif
