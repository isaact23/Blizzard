#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "readWrite.h"

void uci();
void debug(bool value);
void isready();
void setoption(char* name, char* value);
void doregister();
void ucinewgame();
void position(bool startPos, char* fen, int moveCount, MoveNode* moveList);
void go(SearchSettings* settings);
void stop();
void ponderhit();
void quit();

#endif
