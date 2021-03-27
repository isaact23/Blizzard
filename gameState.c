#include "main.h"
#include "gameState.h"

// Returns pointer to dynamically allocated board in opening state.
gameState* openingGameState() {
    // Initialize empty board
    gameState* state = malloc(sizeof(gameState));

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
    char** pieces = malloc(sizeof(char*) * 8);
    for (int i = 0; i < 8; i++) {
        pieces[i] = malloc(sizeof(char) * 8);
    }
    pieces[0][0] = WR;
    pieces[0][1] = WN;
    pieces[0][2] = WB;
    pieces[0][3] = WQ;
    pieces[0][4] = WK;
    pieces[0][5] = WB;
    pieces[0][6] = WN;
    pieces[0][7] = WR;
    for (int i = 0; i < 8; i++) {
        pieces[1][i] = WP;
        for (int j = 2; j < 6; j++) {
            pieces[j][i] = EE;
        }
        pieces[6][i] = BP;
    }
    pieces[7][0] = BR;
    pieces[7][1] = BN;
    pieces[7][2] = BB;
    pieces[7][3] = BQ;
    pieces[7][4] = BK;
    pieces[7][5] = BB;
    pieces[7][6] = BN;
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

// Frees memory in a *gameState.
void freeGameState(gameState* state) {
    for (int i = 0; i < 8; i++) {
        free(state -> pieces[i]);
    }
    free(state -> pieces);
    free(state);
};

// Prints a *gameState to terminal.
void printGameState(gameState* state) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", state -> pieces[7 - i][j]);
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
