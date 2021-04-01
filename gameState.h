#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pieces.h"
#include "moveList.h"

// Store all data in FEN for game state
struct _GameState {
    uint8_t** pieces; // 8x8 board (indexed by rows then cols)
    uint8_t turn;
    uint8_t wck, wcq, bck, bcq; // Castling availability. 0 if unavailable.
    uint8_t en_passant_file; // Column of en passant. Greater than 7 if unavailable.
    uint16_t halfmove_counter;
    uint16_t fullmove_counter;
};
typedef struct _GameState GameState;

// Returns pointer to dynamically allocated opening GameState.
GameState* openingGameState();

// Apply a move to the GameState.
void applyMoveToGameState(GameState* state, Move* move);

// Get fitness level for a GameState.
int32_t getFitness(GameState* state);

// Frees memory in a GameState.
void freeGameState(GameState* state);

// Prints a GameState to the terminal.
void printGameState(GameState* state);

#endif
