#include "gameState.h"

// Returns pointer to dynamically allocated board in opening state.
GameState* openingGameState() {
    // Initialize empty board
    GameState* state = malloc(sizeof(GameState));

    // Initialize piece starting positions
    /*char piecesInit[8][8] = {
        {WR, WN, WB, WQ, WK, WB, WN, WR},
        {WP, WP, WP, WP, WP, WP, WP, WP},
        {EE, EE, EE, EE, EE, EE, EE, EE},
        {EE, EE, EE, EE, EE, EE, EE, EE},
        {EE, EE, EE, EE, EE, EE, EE, EE},
        {EE, EE, EE, EE, EE, EE, EE, EE},
        {BP, BP, BP, BP, BP, BP, BP, BP},
        {BR, BN, BB, BQ, BK, BB, BN, BR}
    };*/
    uint8_t** pieces = malloc(sizeof(uint8_t*) * 8);
    for (int i = 0; i < 8; i++) {
        pieces[i] = malloc(sizeof(uint8_t) * 8);
    }
    // Convention is pieces[x][y].
    pieces[0][0] = WR;
    pieces[1][0] = WN;
    pieces[2][0] = WB;
    pieces[3][0] = WQ;
    pieces[4][0] = WK;
    pieces[5][0] = WB;
    pieces[6][0] = WN;
    pieces[7][0] = WR;
    for (int i = 0; i < 8; i++) {
        pieces[i][1] = WP;
        for (int j = 2; j < 6; j++) {
            pieces[i][j] = EE;
        }
        pieces[i][6] = BP;
    }
    pieces[0][7] = BR;
    pieces[1][7] = BN;
    pieces[2][7] = BB;
    pieces[3][7] = BQ;
    pieces[4][7] = BK;
    pieces[5][7] = BB;
    pieces[6][7] = BN;
    pieces[7][7] = BR;

    state -> pieces = pieces;

    // Initialize default FEN
    state -> turn = WHITE;
    state -> wck = 1;
    state -> wcq = 1;
    state -> bck = 1;
    state -> bcq = 1;
    state -> en_passant_file = 8;
    state -> halfmove_counter = 0;
    state -> fullmove_counter = 0;

    return state;
};

// Apply a move to the GameState.
void applyMoveToGameState(GameState* state, Move* move) {
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
    uint8_t** pieces = state -> pieces;
    for (uint8_t x = 0; x < 8; x++) {
        uint8_t* col = pieces[x];
        for (uint8_t y = 0; y < 8; y++) {
            switch (col[y]) {
                case WP: { fitness += (100 + y); break; }
                case WB: { fitness += 300; break; }
                case WN: { fitness += 300; break; }
                case WR: { fitness += 500; break; }
                case WQ: { fitness += 900; break; }
                case WK: { fitness += 1000000; break; }
                case BP: { fitness -= (100 + y); break; }
                case BB: { fitness -= 300; break; }
                case BN: { fitness -= 300; break; }
                case BR: { fitness -= 500; break; }
                case BQ: { fitness -= 900; break; }
                case BK: { fitness -= 1000000; break; }
            }
        }
    }
    return fitness;
};

// Frees memory in a *gameState.
void freeGameState(GameState* state) {
    for (int i = 0; i < 8; i++) {
        free(state -> pieces[i]);
    }
    free(state -> pieces);
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
}
