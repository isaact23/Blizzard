#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pieces.h"
#include "moveList.h"

// Store all data in FEN for game state
struct _GameState {
    uint8_t pieces[8][8]; // 8x8 board (indexed by x then y)
    uint8_t turn;
    uint8_t wck, wcq, bck, bcq; // Castling availability. 0 if unavailable.
    uint8_t en_passant_file; // Column of en passant. Greater than 7 if unavailable.
    uint16_t halfmove_counter;
    uint16_t fullmove_counter;
    bool isTerminal;
};
typedef struct _GameState GameState;

// Returns pointer to dynamically allocated opening GameState.
GameState* openingGameState();

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
