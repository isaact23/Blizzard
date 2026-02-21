#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "engine.h"
#include "error.h"
#include "interface/readWrite.h"
#include "interface/searchSettings.h"

void uci();
void debug(bool value);
void isready();
void setoption(char* name, char* value);
void ucinewgame();
void position(char* fen, char** moves, int moveCount);
void go();
void stop();
void ponderhit();
void quit();

#endif
