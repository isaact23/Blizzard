#include "moveLister.h"

// Return pointer to list of all possible moves for gameState state, or NULL if failed.
MoveList* listMoves(GameState* state) {
    // Allocate new MoveList
    MoveList* moveList = malloc(sizeof(MoveList));
    if (moveList == NULL) { return NULL; }
    moveList -> moveArray = malloc(DEFAULT_ARRAY_SIZE * sizeof(Move*));
    moveList -> arraySize = DEFAULT_ARRAY_SIZE;

    // Iterate through all squares on the chessboard, listing move for each piece
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char piece = state -> pieces[x][y];
            if (piece == WK || piece == BK) {
                
            } else if (piece == WP || piece == BP) {
                listPawnMoves(moveList, x, y);
            }
        }
    }
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(MoveList* moveList, int x, int y) {
    
}

