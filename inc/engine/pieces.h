#ifndef __PIECES_H__
#define __PIECES_H__

#include <stdint.h>

// Piece colors
#define WHITE 1 << 0
#define BLACK 1 << 1

// Piece types
#define KING 1 << 2
#define QUEEN 1 << 3
#define BISHOP 1 << 4
#define KNIGHT 1 << 5
#define ROOK 1 << 6
#define PAWN 1 << 7

// Piece values defined in centipawns
#define KING_VALUE 0
#define QUEEN_VALUE 900
#define ROOK_VALUE 500
#define BISHOP_VALUE 300
#define KNIGHT_VALUE 300
#define PAWN_VALUE 100

// Piece type colors
#define EMPTY 0
#define EE 0
#define WK (KING   | WHITE)
#define WQ (QUEEN  | WHITE)
#define WB (BISHOP | WHITE)
#define WN (KNIGHT | WHITE)
#define WR (ROOK   | WHITE)
#define WP (PAWN   | WHITE)
#define BK (KING   | BLACK)
#define BQ (QUEEN  | BLACK)
#define BB (BISHOP | BLACK)
#define BN (KNIGHT | BLACK)
#define BR (ROOK   | BLACK)
#define BP (PAWN   | BLACK)

// Determine piece color.
uint8_t getPieceColor(uint8_t piece);

// Get piece character from piece number
char getPieceCharacter(uint8_t piece);

// Get the value of a piece in centipawns.
int32_t getPieceValue(uint8_t piece);

#endif
