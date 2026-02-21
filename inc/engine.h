#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "engine/move.h"

void initialize();
void startPosition();
void setPosition(char* fen, char** moves, int moveCount);
void startSearch();
void stopSearch();
Move* getBestMove();

#endif
