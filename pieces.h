#ifndef PIECES_H
#define PIECES_H

#include <stdint.h>

// Player numbers
#define WHITE 0
#define BLACK 1

// Piece type numbers
#define EMPTY 0
#define EE 0
#define WK 1
#define WQ 2
#define WB 3
#define WN 4
#define WR 5
#define WP 6
#define BK 7
#define BQ 8
#define BB 9
#define BN 10
#define BR 11
#define BP 12

/*#define EE ' '
#define WK 'K'
#define WQ 'Q'
#define WB 'B'
#define WN 'N'
#define WR 'R'
#define WP 'P'
#define BK 'k'
#define BQ 'q'
#define BB 'b'
#define BN 'n'
#define BR 'r'
#define BP 'p'*/

// Determine piece color. Return 0 if white, 1 if black, or 2 if empty.
uint8_t getPieceColor(uint8_t piece);

// Get piece character from piece number
char getPieceCharacter(uint8_t piece);

#endif
