#ifndef __PIECES_H__
#define __PIECES_H__

#include <stdint.h>

// Piece colors
#define WHITE_BIT 1 << 3
#define BLACK_BIT 1 << 4
#define WHITE 1
#define BLACK 2

// Piece types
#define KING 0
#define QUEEN 1
#define BISHOP 2
#define KNIGHT 3
#define ROOK 4
#define PAWN 5

// Piece type colors
#define EMPTY 0
#define EE 0
#define WK (KING   | WHITE_BIT)
#define WQ (QUEEN  | WHITE_BIT)
#define WB (BISHOP | WHITE_BIT)
#define WN (KNIGHT | WHITE_BIT)
#define WR (ROOK   | WHITE_BIT)
#define WP (PAWN   | WHITE_BIT)
#define BK (KING   | BLACK_BIT)
#define BQ (QUEEN  | BLACK_BIT)
#define BB (BISHOP | BLACK_BIT)
#define BN (KNIGHT | BLACK_BIT)
#define BR (ROOK   | BLACK_BIT)
#define BP (PAWN   | BLACK_BIT)

// Determine piece color.
uint8_t getPieceColor(uint8_t piece);

// Get piece character from piece number
char getPieceCharacter(uint8_t piece);

#endif
