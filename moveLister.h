#ifndef MOVELISTER_H
#define MOVELISTER_H

#include "main.h"
#include "gameState.h"

#define DEFAULT_ARRAY_SIZE 20

// Store data for a move
struct _Move {
    uint8_t from_x;
    uint8_t from_y;
    uint8_t to_x;
    uint8_t to_y;
    uint8_t promotion;
};
typedef struct _Move Move;

// Store multiple moves
struct _MoveList {
    Move** moveArray;
    uint16_t moveCount;
    uint16_t arraySize;
};
typedef struct _MoveList MoveList;

// Return pointer to list of all possible moves for gameState state, or NULL if failed.
MoveList* listMoves(GameState* state);

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(MoveList* moveList, int x, int y);
// List rook moves at coordinate (x, y) and update moveList.
static void listRookMoves(MoveList* moveList, int x, int y);
// List knight moves at coordinate (x, y) and update moveList.
static void listKnightMoves(MoveList* moveList, int x, int y);
// List bishop moves at coordinate (x, y) and update moveList.
static void listBishopMoves(MoveList* moveList, int x, int y);
// List queen moves at coordinate (x, y) and update moveList.
static void listQueenMoves(MoveList* moveList, int x, int y);
// List king moves at coordinate (x, y) and update moveList.
static void listRookMoves(MoveList* moveList, int x, int y);

// Add a move to a moveListStruct.
static void addMove(MoveList* moveList, Move* move);

#endif
