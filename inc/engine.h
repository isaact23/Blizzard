#ifndef __ENGINE_H__
#define __ENGINE_H__

void initialize();
void startPosition();
void setPosition(char* fen, char** moves, int moveCount);
void startSearch();
void stopSearch();
char* getBestMove();

#endif
