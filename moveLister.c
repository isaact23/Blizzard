#include "moveList.h"
#include "moveLister.h"

// Return pointer to list of moves for GameState, or NULL if failed.
// Moves that leave king exposed are allowed.
MoveList* listMoves(GameState* gameState) {
    // Allocate new MoveList
    MoveList* moveList = emptyMoveList();

    // Iterate through all squares on the chessboard, listing move for each piece
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char piece = gameState -> pieces[x][y];
            if (piece == WK || piece == BK) {
                
            } else if (piece == WP || piece == BP) {
                listPawnMoves(gameState, moveList, x, y);
            }
        }
    }

    return moveList;
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* gameState, MoveList* moveList, int x, int y) {
    if (gameState -> pieces[x][y] == WP) {

    }
    else if (gameState -> pieces[x][y] == BP) {

    }
}

