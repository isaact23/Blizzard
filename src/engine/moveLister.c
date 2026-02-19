#include "moveLister.h"

// Return pointer to list of moves for GameState, or NULL if failed.
// Moves that leave king exposed are allowed.
MoveList* listMoves(GameState* state) {
    // Allocate new MoveList
    MoveList* moveList = createMoveList();

    // Iterate through all squares on the chessboard, listing move for each piece
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            uint8_t piece = state -> pieces[x][y];
            if (piece != EMPTY) {
                if (state -> turn == WHITE) {
                    if (piece == WK) {
                        listKingMoves(state, moveList, x, y);
                    } else if (piece == WP) {
                        listPawnMoves(state, moveList, x, y);
                    } else if (piece == WN) {
                        listKnightMoves(state, moveList, x, y);
                    } else if (piece == WB) {
                        listBishopMoves(state, moveList, x, y);
                    } else if (piece == WR) {
                        listRookMoves(state, moveList, x, y);
                    } else if (piece == WQ) {
                        listQueenMoves(state, moveList, x, y);
                    }
                } else {
                    if (piece == BK) {
                        listKingMoves(state, moveList, x, y);
                    } else if (piece == BP) {
                        listPawnMoves(state, moveList, x, y);
                    } else if (piece == BN) {
                        listKnightMoves(state, moveList, x, y);
                    } else if (piece == BB) {
                        listBishopMoves(state, moveList, x, y);
                    } else if (piece == BR) {
                        listRookMoves(state, moveList, x, y);
                    } else if (piece == BQ) {
                        listQueenMoves(state, moveList, x, y);
                    }
                }
            }
        }
    }

    return moveList;
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    if (state -> pieces[x][y] == WP) {
        // Move forward 1
        if (y < 7 && state -> pieces[x][y + 1] == EMPTY) {
            addMove(moveList, x, y, x, y + 1, 0);
            // Promotion
            if (y == 6) {
                addMove(moveList, x, 6, x, 7, 1);
                addMove(moveList, x, 6, x, 7, 2);
                addMove(moveList, x, 6, x, 7, 3); 
                addMove(moveList, x, 6, x, 7, 4); 
            }
        }
        // Move forward 2
        if (y == 1 && state -> pieces[x][2] == EMPTY && state -> pieces[x][3] == EMPTY) {
            addMove(moveList, x, 1, x, 3, 0);
        }
        // Capture (left)
        if (x > 0 && y < 7 && getPieceColor(state -> pieces[x - 1][y + 1]) == BLACK) {
            addMove(moveList, x, y, x - 1, y + 1, 0);
            // Capture promotion (left)
            if (y == 6) {
                addMove(moveList, x, 6, x - 1, 7, 1);
                addMove(moveList, x, 6, x - 1, 7, 2);
                addMove(moveList, x, 6, x - 1, 7, 3);
                addMove(moveList, x, 6, x - 1, 7, 4);
            }
        }
        // Capture (right)
        if (x < 7 && y < 7 && getPieceColor(state -> pieces[x + 1][y + 1]) == BLACK) {
            addMove(moveList, x, y, x + 1, y + 1, 0);
            // Capture promotion (right)
            if (y == 6) {
                addMove(moveList, x, 6, x + 1, 7, 1);
                addMove(moveList, x, 6, x + 1, 7, 2);
                addMove(moveList, x, 6, x + 1, 7, 3);
                addMove(moveList, x, 6, x + 1, 7, 4);
            }
        }
        // En passant
        uint8_t passantFile = state -> en_passant_file;
        if (passantFile < 8 && y == 4) {
            if (x > 0 && passantFile == x - 1 && state -> pieces[x - 1][5] == EMPTY) {
                addMove(moveList, x, 4, x - 1, 5, 0);
            }
            if (x < 7 && passantFile == x + 1 && state -> pieces[x + 1][5] == EMPTY) {
                addMove(moveList, x, 4, x + 1, 5, 0);
            }
        }
    }
    else if (state -> pieces[x][y] == BP) {
        // Move forward 1
        if (y > 0 && state -> pieces[x][y - 1] == EMPTY) {
            addMove(moveList, x, y, x, y - 1, 0);
            // Promotion
            if (y == 1) {
                addMove(moveList, x, 1, x, 0, 1);
                addMove(moveList, x, 1, x, 0, 2);
                addMove(moveList, x, 1, x, 0, 3); 
                addMove(moveList, x, 1, x, 0, 4); 
            }
        }
        // Move forward 2
        if (y == 6 && state -> pieces[x][5] == EMPTY && state -> pieces[x][4] == EMPTY) {
            addMove(moveList, x, 6, x, 4, 0);
        }
        // Capture (left)
        if (x > 0 && y > 0 && getPieceColor(state -> pieces[x - 1][y - 1]) == WHITE) {
            addMove(moveList, x, y, x - 1, y - 1, 0);
            // Capture promotion (left)
            if (y == 1) {
                addMove(moveList, x, 1, x - 1, 0, 1);
                addMove(moveList, x, 1, x - 1, 0, 2);
                addMove(moveList, x, 1, x - 1, 0, 3);
                addMove(moveList, x, 1, x - 1, 0, 4);
            }
        }
        // Capture (right)
        if (x < 7 && y > 0 && getPieceColor(state -> pieces[x + 1][y - 1]) == WHITE) {
            addMove(moveList, x, y, x + 1, y - 1, 0);
            // Capture promotion (right)
            if (y == 1) {
                addMove(moveList, x, 1, x + 1, 0, 1);
                addMove(moveList, x, 1, x + 1, 0, 2);
                addMove(moveList, x, 1, x + 1, 0, 3);
                addMove(moveList, x, 1, x + 1, 0, 4);
            }
        }
        // En passant
        uint8_t passantFile = state -> en_passant_file;
        if (passantFile < 8 && y == 3) {
            if (x > 0 && passantFile == x - 1 && state -> pieces[x - 1][2] == EMPTY) {
                addMove(moveList, x, 3, x - 1, 2, 0);
            }
            if (x < 7 && passantFile == x + 1 && state -> pieces[x + 1][2] == EMPTY) {
                addMove(moveList, x, 3, x + 1, 2, 0);
            }
        }
    }
}

// List knight moves at coordinate (x, y) and update moveList.
static void listKnightMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t color = getPieceColor(state -> pieces[x][y]);
    if (x > 0) {
        if (y > 1) {
            if (getPieceColor(state -> pieces[x - 1][y - 2]) != color) {
                addMove(moveList, x, y, x - 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(state -> pieces[x - 1][y + 2]) != color) {
                addMove(moveList, x, y, x - 1, y + 2, 0);
            }
        }
        if (x > 1) {
            if (y > 0) {
                if (getPieceColor(state -> pieces[x - 2][y - 1]) != color) {
                    addMove(moveList, x, y, x - 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(state -> pieces[x - 2][y + 1]) != color) {
                    addMove(moveList, x, y, x - 2, y + 1, 0);
                }
            }
        }
    }
    if (x < 7) {
        if (y > 1) {
            if (getPieceColor(state -> pieces[x + 1][y - 2]) != color) {
                addMove(moveList, x, y, x + 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(state -> pieces[x + 1][y + 2]) != color) {
                addMove(moveList, x, y, x + 1, y + 2, 0);
            }
        }
        if (x < 6) {
            if (y > 0) {
                if (getPieceColor(state -> pieces[x + 2][y - 1]) != color) {
                    addMove(moveList, x, y, x + 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(state -> pieces[x + 2][y + 1]) != color) {
                    addMove(moveList, x, y, x + 2, y + 1, 0);
                }
            }
        }
    }
}

// List rook moves at coordinate (x, y) and update moveList.
static void listRookMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t color = getPieceColor(state -> pieces[x][y]);
    uint8_t obstacleColor;

    // Left
    for (int8_t i = x - 1; i >= 0; i--) {
        obstacleColor = getPieceColor(state -> pieces[i][y]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, i, y, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Right
    for (int8_t i = x + 1; i < 8; i++) {
        obstacleColor = getPieceColor(state -> pieces[i][y]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, i, y, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Down
    for (int8_t i = y - 1; i >= 0; i--) {
        obstacleColor = getPieceColor(state -> pieces[x][i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x, i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Up
    for (int8_t i = y + 1; i < 8; i++) {
        obstacleColor = getPieceColor(state -> pieces[x][i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x, i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
};

// List bishop moves at coordinate (x, y) and update moveList.
static void listBishopMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t color = getPieceColor(state -> pieces[x][y]);
    uint8_t obstacleColor;

    // Down-left
    for (uint8_t i = 1; i <= x && i <= y; i++) {
        uint8_t obstacleColor = getPieceColor(state -> pieces[x - i][y - i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x - i, y - i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Up-left
    for (uint8_t i = 1; i <= x && i <= 7 - y; i++) {
        uint8_t obstacleColor = getPieceColor(state -> pieces[x - i][y + i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x - i, y + i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Down-right
    for (uint8_t i = 1; i <= 7 - x && i <= y; i++) {
        uint8_t obstacleColor = getPieceColor(state -> pieces[x + i][y - i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x + i, y - i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
    // Up-right
    for (uint8_t i = 1; i <= 7 - x && i <= 7 - y; i++) {
        uint8_t obstacleColor = getPieceColor(state -> pieces[x + i][y + i]);
        if (obstacleColor != color) {
            addMove(moveList, x, y, x + i, y + i, 0);
            if (obstacleColor != EMPTY) {
                break;
            }
        } else {
            break;
        }
    }
};

// List queen moves at coordinate (x, y) and update moveList.
static void listQueenMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    listRookMoves(state, moveList, x, y);
    listBishopMoves(state, moveList, x, y);
};

// List king moves at coordinate (x, y) and update moveList.
static void listKingMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t color = getPieceColor(state -> pieces[x][y]);
    if (x > 0) {
        if (color != getPieceColor(state -> pieces[x - 1][y])) {
            addMove(moveList, x, y, x - 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(state -> pieces[x - 1][y - 1])) {
                addMove(moveList, x, y, x - 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(state -> pieces[x - 1][y + 1])) { 
                addMove(moveList, x, y, x - 1, y + 1, 0);
            }
        }
    }
    if (y > 0) {
        if (color != getPieceColor(state -> pieces[x][y - 1])) {
            addMove(moveList, x, y, x, y - 1, 0);
        }
    }
    if (y < 7) {
        if (color != getPieceColor(state -> pieces[x][y + 1])) {
            addMove(moveList, x, y, x, y + 1, 0);
        }
    }
    if (x < 7) {
        if (color != getPieceColor(state -> pieces[x + 1][y])) {
            addMove(moveList, x, y, x + 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(state -> pieces[x + 1][y - 1])) {
                addMove(moveList, x, y, x + 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(state -> pieces[x + 1][y + 1])) { 
                addMove(moveList, x, y, x + 1, y + 1, 0);
            }
        }
    }
};
