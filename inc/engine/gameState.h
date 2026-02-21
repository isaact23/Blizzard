#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "engine/longAlgConvert.h"
#include "engine/pieces.h"
#include "engine/moveList.h"
#include "engine/settings.h"

#define CAN_CASTLE_WHITE_KINGSIDE (1 << 1)
#define CAN_CASTLE_WHITE_QUEENSIDE (1 << 2)
#define CAN_CASTLE_BLACK_KINGSIDE (1 << 3)
#define CAN_CASTLE_BLACK_QUEENSIDE (1 << 4)
#define CAN_CASTLE_ALL 0xF

// Store all data in FEN for game state
struct _GameState {
    uint8_t pieces[8][8]; // 8x8 board (indexed by x then y)
    uint8_t turn;
    uint8_t castleFlags; // Castling availability (indicated by 1 bits)
    uint8_t enPassantFile; // Column of en passant. Greater than 7 if unavailable.
    uint16_t halfMoves;
    uint16_t fullMoves;
    bool isTerminal;
};
typedef struct _GameState GameState;

// Returns pointer to dynamically allocated opening GameState.
GameState* openingGameState();

// Create a GameState from a given FEN (Forsyth-Edwards Notation)
GameState* gameStateFromFen(char* fen);

// Apply a move to the GameState.
void applyMoveToGameState(GameState* state, Move* move);

// Get fitness level for a GameState.
int32_t getFitness(GameState* state);

// Return a pointer to an identical gameState to the provided one.
GameState* copyGameState(GameState* state);

// Frees memory in a GameState.
void freeGameState(GameState* state);

// Prints a GameState to the terminal.
void printGameState(GameState* state);

#endif
