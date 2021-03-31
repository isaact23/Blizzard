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
            if (gameState -> turn == WHITE) {
                if (piece == WK) {
                    
                } else if (piece == WP) {
                    listPawnMoves(gameState, moveList, x, y);
                }
            } else {

            }
        }
    }

    return moveList;
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* gameState, MoveList* moveList, int x, int y) {
    uint8_t** pieces = gameState -> pieces;
    if (pieces[x][y] == WP) {
        // Move forward 1
        if (y < 7 && pieces[x][y + 1] == EMPTY) {
            addMove(moveList, x, y, x, y + 1, 0);
            // Promotion
            if (y == 6) {
                addMove(moveList, x, 6, x, 7, 1);
                addMove(moveList, x, 6, x, 7, 2);
                addMove(moveList, x, 6, x, 7, 3); 
            }
        }
        // Move forward 2
        if (y == 1 && pieces[x][2] == EMPTY && pieces[x][3] == EMPTY) {
            addMove(moveList, x, 1, x, 3, 0);
        }
        // Capture (left)
        if (x > 0 && y < 7 && getPieceColor(pieces[x - 1][y + 1]) == BLACK) {
            addMove(moveList, x, y, x - 1, y + 1, 0);
            // Capture promotion (left)
            if (y == 6) {
                addMove(moveList, x, 6, x - 1, 7, 1);
                addMove(moveList, x, 6, x - 1, 7, 2);
                addMove(moveList, x, 6, x - 1, 7, 3);
            }
        }
        // Capture (right)
        if (x < 7 && y < 7 && getPieceColor(pieces[x + 1][y + 1]) == BLACK) {
            addMove(moveList, x, y, x + 1, y + 1, 0);
            // Capture promotion (right)
            if (y == 6) {
                addMove(moveList, x, 6, x + 1, 7, 1);
                addMove(moveList, x, 6, x + 1, 7, 2);
                addMove(moveList, x, 6, x + 1, 7, 3);
            }
        }
        // En passant
        uint8_t passantFile = gameState -> en_passant_file;
        if (passantFile < 8 && y == 4) {
            if (x > 0 && passantFile == x - 1 && pieces[x - 1][5] == EMPTY) {
                addMove(moveList, x, 4, x - 1, 5, 0);
            }
            if (x < 7 && passantFile == x + 1 && pieces[x + 1][5] == EMPTY) {
                addMove(moveList, x, 4, x + 1, 5, 0);
            }
        }
    }
    else if (pieces[x][y] == BP) {
        // Move forward 1
        if (y > 0 && pieces[x][y - 1] == EMPTY) {
            addMove(moveList, x, y, x, y - 1, 0);
            // Promotion
            if (y == 1) {
                addMove(moveList, x, 1, x, 0, 1);
                addMove(moveList, x, 1, x, 0, 2);
                addMove(moveList, x, 1, x, 0, 3); 
            }
        }
        // Move forward 2
        if (y == 6 && pieces[x][5] == EMPTY && pieces[x][4] == EMPTY) {
            addMove(moveList, x, 6, x, 4, 0);
        }
        // Capture (left)
        if (x > 0 && y > 0 && getPieceColor(pieces[x - 1][y - 1]) == WHITE) {
            addMove(moveList, x, y, x - 1, y - 1, 0);
            // Capture promotion (left)
            if (y == 1) {
                addMove(moveList, x, 1, x - 1, 0, 1);
                addMove(moveList, x, 1, x - 1, 0, 2);
                addMove(moveList, x, 1, x - 1, 0, 3);
            }
        }
        // Capture (right)
        if (x < 7 && y > 0 && getPieceColor(pieces[x + 1][y - 1]) == WHITE) {
            addMove(moveList, x, y, x + 1, y - 1, 0);
            // Capture promotion (right)
            if (y == 1) {
                addMove(moveList, x, 1, x + 1, 0, 1);
                addMove(moveList, x, 1, x + 1, 0, 2);
                addMove(moveList, x, 1, x + 1, 0, 3);
            }
        }
        // En passant
        uint8_t passantFile = gameState -> en_passant_file;
        if (passantFile < 8 && y == 3) {
            if (x > 0 && passantFile == x - 1 && pieces[x - 1][2] == EMPTY) {
                addMove(moveList, x, 3, x - 1, 2, 0);
            }
            if (x < 7 && passantFile == x + 1 && pieces[x + 1][2] == EMPTY) {
                addMove(moveList, x, 3, x + 1, 2, 0);
            }
        }
    }
}

