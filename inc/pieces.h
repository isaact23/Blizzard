#ifndef PIECES_H
#define PIECES_H

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
#define WK KING   | WHITE
#define WQ QUEEN  | WHITE
#define WB BISHOP | WHITE
#define WN KNIGHT | WHITE
#define WR ROOK   | WHITE
#define WP PAWN   | WHITE
#define BK KING   | BLACK
#define BQ QUEEN  | BLACK
#define BB BISHOP | BLACK
#define BN KNIGHT | BLACK
#define BR ROOK   | BLACK
#define BP PAWN   | BLACK

// Determine piece color.
uint8_t getPieceColor(uint8_t piece);

// Get piece character from piece number
char getPieceCharacter(uint8_t piece);

#endif
