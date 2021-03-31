#include "pieces.h"

// Determine piece color. Return 0 if white or 1 if black.
uint8_t getPieceColor(uint8_t piece) {
    if (piece == 0) { return 2; } // Empty
    if (piece < 7) { return 0; } // White
    return 1; // Black
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
