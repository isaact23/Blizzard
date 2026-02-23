#include "engine/gameState.h"

// Returns pointer to dynamically allocated board in opening state.
GameState* openingGameState() {
    return gameStateFromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

// Create a GameState from a given FEN (Forsyth-Edwards Notation)
GameState* gameStateFromFen(char* fen) {
    GameState* state = malloc(sizeof(GameState));
    int y = 7;
    int x = 0;
    int i = 0;

    // Read piece layout
    while (fen[i] != ' ') {
        switch (fen[i]) {
            case '0': { break; }
            case '1': { break; }
            case '2': { x += 1; break; }
            case '3': { x += 2; break; }
            case '4': { x += 3; break; }
            case '5': { x += 4; break; }
            case '6': { x += 5; break; }
            case '7': { x += 6; break; }
            case '8': { x += 7; break; }
            case 'k': { state->pieces[x][y] = KING | BLACK; break; }
            case 'q': { state->pieces[x][y] = QUEEN | BLACK; break; }
            case 'r': { state->pieces[x][y] = ROOK | BLACK; break; }
            case 'b': { state->pieces[x][y] = BISHOP | BLACK; break; }
            case 'n': { state->pieces[x][y] = KNIGHT | BLACK; break; }
            case 'p': { state->pieces[x][y] = PAWN | BLACK; break; }
            case 'K': { state->pieces[x][y] = KING | WHITE; break; }
            case 'Q': { state->pieces[x][y] = QUEEN | WHITE; break; }
            case 'R': { state->pieces[x][y] = ROOK | WHITE; break; }
            case 'B': { state->pieces[x][y] = BISHOP | WHITE; break; }
            case 'N': { state->pieces[x][y] = KNIGHT | WHITE; break; }
            case 'P': { state->pieces[x][y] = PAWN | WHITE; break; }
            case '/': { x = -1; y--; break; }
            default: {
                error("Encountered unknown character %s in FEN string", fen[i]);
            }
        }
        x++;
        i++;
    }
    i++;

    // Read turn
    switch (fen[i]) {
        case 'w': {state -> turn = WHITE; break;}
        case 'b': {state -> turn = BLACK; break;}
        default: {
            error("Could not identify turn in FEN string");
        }
    }
    i += 2;

    // Read castling status
    while (fen[i] != ' ') {
        switch (fen[i]) {
            case 'K': {state -> castleFlags |= CAN_CASTLE_WHITE_KINGSIDE; break;}
            case 'Q': {state -> castleFlags |= CAN_CASTLE_WHITE_QUEENSIDE; break;}
            case 'k': {state -> castleFlags |= CAN_CASTLE_BLACK_KINGSIDE; break;}
            case 'q': {state -> castleFlags |= CAN_CASTLE_BLACK_QUEENSIDE; break;}
            default: {
                error("Could not identify castling status in FEN string");
            }
        }
        i++;
    }
    i++;

    // Read en passant status
    if (fen[i] == '-') {
        i += 2;
    }
    else {
        state -> enPassantFile = fileCharToNum(fen[i]);
        i += 3;
    }

    // Read halfmove
    char numString[512];
    int j = 0;
    while (fen[i] != ' ' && i < 512) {
        numString[j] = fen[i];
        i++; j++;
    }
    numString[j] = '\0';
    state -> halfMoves = (uint16_t) atoi(numString);
    i++;

    // Read full move
    j = 0;
    while (fen[i] != ' ' && i < 512) {
        numString[j] = fen[i];
        i++; j++;
    }
    numString[j] = '\0';
    state -> fullMoves = (uint16_t) atoi(numString);

    state -> winner = EMPTY;

    return state;
}

// Apply a move to the GameState.
void applyMoveToGameState(GameState* state, Move* move) {
    // If king is captured, game is over.
    uint8_t captured = state -> pieces[move -> to_x][move -> to_y];
    if (captured == WK) {
        state -> winner = BLACK;
        return;
    }
    else if (captured == BK) {
        state -> winner = WHITE;
        return;
    }

    // Move the piece
    state -> pieces[move -> to_x][move -> to_y] = state -> pieces[move -> from_x][move -> from_y];
    state -> pieces[move -> from_x][move -> from_y] = EMPTY;
    if (state -> turn == WHITE) {
        state -> turn = BLACK;
    } else {
        state -> turn = WHITE;
    }

    // Castling
    if (move->from_x == 4) {
        if (move->from_y == 0 && move->to_y == 0) {
            if (move->to_x == 6) {
                state -> pieces[7][0] = EMPTY;
                state -> pieces[5][0] = WHITE | ROOK;
                state -> castleFlags &= ~CAN_CASTLE_WHITE_KINGSIDE
            }
            else if (move->to_x == 2) {
                state -> pieces[0][0] = EMPTY;
                state -> pieces[2][0] = WHITE | ROOK;
                state -> castleFlags &= ~CAN_CASTLE_WHITE_QUEENSIDE
            }
        }
        else if (move->from_y == 7 && move->to_y == 7) {
            if (move->to_x == 6) {
                state -> pieces[7][7] = EMPTY;
                state -> pieces[5][7] = BLACK | ROOK;
                state -> castleFlags &= ~CAN_CASTLE_BLACK_KINGSIDE
            }
            else if (move->to_x == 2) {
                state -> pieces[0][7] = EMPTY;
                state -> pieces[2][7] = BLACK | ROOK;
                state -> castleFlags &= ~CAN_CASTLE_BLACK_QUEENSIDE
            }
        }
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
