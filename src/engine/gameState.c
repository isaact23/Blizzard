#include "engine/gameState.h"

// Returns pointer to dynamically allocated board in opening state.
GameState* openingGameState() {
    // Initialize empty board
    GameState* state = malloc(sizeof(GameState));

    // Convention is pieces[x][y].
    state->pieces[0][0] = WR;
    state->pieces[1][0] = WN;
    state->pieces[2][0] = WB;
    state->pieces[3][0] = WQ;
    state->pieces[4][0] = WK;
    state->pieces[5][0] = WB;
    state->pieces[6][0] = WN;
    state->pieces[7][0] = WR;
    for (int i = 0; i < 8; i++) {
        state->pieces[i][1] = WP;
        for (int j = 2; j < 6; j++) {
            state->pieces[i][j] = EE;
        }
        state->pieces[i][6] = BP;
    }
    state->pieces[0][7] = BR;
    state->pieces[1][7] = BN;
    state->pieces[2][7] = BB;
    state->pieces[3][7] = BQ;
    state->pieces[4][7] = BK;
    state->pieces[5][7] = BB;
    state->pieces[6][7] = BN;
    state->pieces[7][7] = BR;

    // Initialize default FEN
    state -> turn = WHITE;
    state -> castleFlags = CAN_CASTLE_ALL;
    state -> enPassantFile = 8;
    state -> isTerminal = false;
    state -> halfMoves = 0;
    state -> fullMoves = 0;

    return state;
};

// Apply a move to the GameState.
void applyMoveToGameState(GameState* state, Move* move) {
    // If king is captured, game is over.
    uint8_t captured = state -> pieces[move -> to_x][move -> to_y];
    if (captured == WK || captured == BK) {
        state -> isTerminal = true;
    }

    // Move the piece
    state -> pieces[move -> to_x][move -> to_y] = state -> pieces[move -> from_x][move -> from_y];
    state -> pieces[move -> from_x][move -> from_y] = EMPTY;
    if (state -> turn == WHITE) {
        state -> turn = BLACK;
    } else {
        state -> turn = WHITE;
    }
}

// Get fitness level for a GameState.
int32_t getFitness(GameState* state) {
    int32_t fitness = 0;
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            switch (state -> pieces[x][y]) {
                case WP: { fitness += (100 + y); break; }
                case WB: { fitness += (300 + (y * 2)); break; }
                case WN: { fitness += (300 + (y * 2)); break; }
                case WR: { fitness += (500 + (y * 3)); break; }
                case WQ: { fitness += (900 + (y * 3)); break; }
                case WK: { fitness += FITNESS_MAX; break; }
                case BP: { fitness -= (100 - y); break; }
                case BB: { fitness -= (300 - (y * 2)); break; }
                case BN: { fitness -= (300 - (y * 2)); break; }
                case BR: { fitness -= (500 - (y * 3)); break; }
                case BQ: { fitness -= (900 - (y * 3)); break; }
                case BK: { fitness -= FITNESS_MAX; break; }
            }
        }
    }
    return fitness;
};

// Return a pointer to an identical gameState to the provided one.
GameState* copyGameState(GameState* state) {
    GameState* newState = malloc(sizeof(GameState));
    memcpy(newState, state, sizeof(GameState));
    
    return newState;
}

// Frees memory in a GameState.
void freeGameState(GameState* state) {
    free(state);
};

// Prints a *GameState to terminal.
void printGameState(GameState* state) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", getPieceCharacter(state -> pieces[j][7 - i]));
            if (j < 7) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 7) {
            printf("--+---+---+---+---+---+---+--\n");
        }
    }
    printf("\n\n");
}
