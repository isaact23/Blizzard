#include "engine/pieces.h"

// Determine piece color.
uint8_t getPieceColor(uint8_t piece) {
    if (piece & WHITE) return WHITE;
    if (piece & BLACK) return BLACK;
    return EMPTY;
}

// Get piece character from piece number
char getPieceCharacter(uint8_t piece) {
    switch (piece) {
        case EMPTY: { return ' '; }
        case WK: { return 'K'; }
        case WQ: { return 'Q'; }
        case WB: { return 'B'; }
        case WN: { return 'N'; }
        case WR: { return 'R'; }
        case WP: { return 'P'; }
        case BK: { return 'k'; }
        case BQ: { return 'q'; }
        case BB: { return 'b'; }
        case BN: { return 'n'; }
        case BR: { return 'r'; }
        case BP: { return 'p'; }
        default: { return ' '; }
    }
};

// Get the value of a piece in centipawns.
int32_t getPieceValue(uint8_t piece) {
    int32_t value = 0;
    if (piece == EMPTY) return 0;
    if (piece & KING) value = KING_VALUE;
    if (piece & QUEEN) value = QUEEN_VALUE;
    if (piece & ROOK) value = ROOK_VALUE;
    if (piece & BISHOP) value = BISHOP_VALUE;
    if (piece & KNIGHT) value = KNIGHT_VALUE;
    if (piece & PAWN) value = PAWN_VALUE;
    if (piece & BLACK) value *= -1;
    return value;
}
