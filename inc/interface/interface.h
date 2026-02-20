#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "engine.h"
#include "readWrite.h"
#include "searchSettings.h"

void uci();
void debug(bool value);
void isready();
void setoption(char* name, char* value);
void ucinewgame();
void position(bool startPos, char* fen, char** moves, int moveCount);
void go(SearchSettings* settings);
void stop();
void ponderhit();
void quit();

#endif
