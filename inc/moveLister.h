#ifndef MOVELISTER_H
#define MOVELISTER_H

#include "pieces.h"
#include "moveList.h"
#include "gameState.h"

// Return pointer to list of all possible moves for gameState state, or NULL if failed.
MoveList* listMoves(GameState* gameState);

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

// List knight moves at coordinate (x, y) and update moveList.
static void listKnightMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

// List rook moves at coordinate (x, y) and update moveList.
static void listRookMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

// List bishop moves at coordinate (x, y) and update moveList.
static void listBishopMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

// List queen moves at coordinate (x, y) and update moveList.
static void listQueenMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

// List king moves at coordinate (x, y) and update moveList.
static void listKingMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y);

#endif
