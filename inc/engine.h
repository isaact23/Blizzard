#ifndef __ENGINE_H__
#define __ENGINE_H__

void initialize();
void startPosition();
void setPosition(char* fen, Move* moves, int moveCount);
void startSearch();
void stopSearch();
Move* getBestMove();

#endif
