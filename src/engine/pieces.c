#include "pieces.h"

// Determine piece color.
uint8_t getPieceColor(uint8_t piece) {
    if (piece & WHITE_BIT) return WHITE;
    if (piece & BLACK_BIT) return BLACK;
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
