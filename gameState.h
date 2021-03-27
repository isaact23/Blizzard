#ifndef GAMESTATE_H
#define GAMESTATE_H

// Store all data in FEN for game state
struct _gameState {
    char** pieces; // 8x8 board (indexed by rows then cols)
    uint8_t turn;
    uint8_t wck, wcq, bck, bcq; // Castling availability. 0 if unavailable.
    uint8_t en_passant_file; // Column of en passant. Greater than 7 if unavailable.
    uint16_t halfmove_counter;
    uint16_t fullmove_counter;
};
typedef struct _gameState gameState;

// Store data for a move
struct _move {
    uint8_t from_x;
    uint8_t from_y;
    uint8_t to_x;
    uint8_t to_y;
    uint8_t promotion;
};
typedef struct _move move;

// Returns pointer to dynamically allocated opening gameState.
gameState* openingBoard();

// Frees memory in a *gameState.
void freeBoard(gameState* state);

// Prints a gameState to the terminal.
void printBoard(gameState* state);

#endif
