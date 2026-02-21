#ifndef __ENGINE_H__
#define __ENGINE_H__

void initialize();
void setPosition(char* fen, char** moves, int moveCount);
void startSearch();
void stopSearch();
void shutdown();
char* getBestMove();

#endif
