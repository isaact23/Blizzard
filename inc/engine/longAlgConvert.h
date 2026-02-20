#ifndef __LONG_ALT_CONVERT_H__
#define __LONG_ALT_CONVERT_H__

#include "engine/move.h"
#include "engine/pieces.h"
#include <stdlib.h>

/* Convert long algebraic notation to the internal move representation. */
Move* longAlgToMove(char* moveStr);

#endif
