#include "moveLister.h"

// Return pointer to list of moves for GameState, or NULL if failed.
// Moves that leave king exposed are allowed.
MoveList* listMoves(GameState* gameState) {
    // Allocate new MoveList
    MoveList* moveList = emptyMoveList();

    // Iterate through all squares on the chessboard, listing move for each piece
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            uint8_t piece = gameState -> pieces[x][y];
            if (piece != EMPTY) {
                if (gameState -> turn == WHITE) {
                    if (piece == WK) {
                        listKingMoves(gameState, moveList, x, y);
                    } else if (piece == WP) {
                        listPawnMoves(gameState, moveList, x, y);
                    } else if (piece == WN) {
                        listKnightMoves(gameState, moveList, x, y);
                    } else if (piece == WB) {
                        listBishopMoves(gameState, moveList, x, y);
                    } else if (piece == WR) {
                        listRookMoves(gameState, moveList, x, y);
                    } else { // Queen
                        listQueenMoves(gameState, moveList, x, y);
                    }
                } else {
                    if (piece == BK) {
                        listKingMoves(gameState, moveList, x, y);
                    } else if (piece == BP) {
                        listPawnMoves(gameState, moveList, x, y);
                    } else if (piece == BN) {
                        listKnightMoves(gameState, moveList, x, y);
                    } else if (piece == BB) {
                        listBishopMoves(gameState, moveList, x, y);
                    } else if (piece == BR) {
                        listRookMoves(gameState, moveList, x, y);
                    } else { // Queen
                        listQueenMoves(gameState, moveList, x, y);
                    }
                }
            }
        }
    }

    return moveList;
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
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

// List knight moves at coordinate (x, y) and update moveList.
static void listKnightMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t** pieces = gameState -> pieces;
    uint8_t color = getPieceColor(pieces[x][y]);
    if (x > 0) {
        if (y > 1) {
            if (getPieceColor(pieces[x - 1][y - 2]) != color) {
                addMove(moveList, x, y, x - 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(pieces[x - 1][y + 2]) != color) {
                addMove(moveList, x, y, x - 1, y + 2, 0);
            }
        }
        if (x > 1) {
            if (y > 0) {
                if (getPieceColor(pieces[x - 2][y - 1]) != color) {
                    addMove(moveList, x, y, x - 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(pieces[x - 2][y + 1]) != color) {
                    addMove(moveList, x, y, x - 2, y + 1, 0);
                }
            }
        }
    }
    if (x < 7) {
        if (y > 1) {
            if (getPieceColor(pieces[x + 1][y - 2]) != color) {
                addMove(moveList, x, y, x + 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(pieces[x + 1][y + 2]) != color) {
                addMove(moveList, x, y, x + 1, y + 2, 0);
            }
        }
        if (x < 6) {
            if (y > 0) {
                if (getPieceColor(pieces[x + 2][y - 1]) != color) {
                    addMove(moveList, x, y, x + 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(pieces[x + 2][y + 1]) != color) {
                    addMove(moveList, x, y, x + 2, y + 1, 0);
                }
            }
        }
    }
};

// If NOT same color,
    // Capture
    // If opposite color,
        // Break

// List rook moves at coordinate (x, y) and update moveList.
static void listRookMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t** pieces = gameState -> pieces;
    uint8_t color = getPieceColor(pieces[x][y]);
    uint8_t obstacleColor;

    // Left
    for (int8_t i = x - 1; i >= 0; i--) {
        obstacleColor = getPieceColor(pieces[i][y]);
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
        obstacleColor = getPieceColor(pieces[i][y]);
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
        obstacleColor = getPieceColor(pieces[x][i]);
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
        obstacleColor = getPieceColor(pieces[x][i]);
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
static void listBishopMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t** pieces = gameState -> pieces;
    uint8_t color = getPieceColor(pieces[x][y]);
    uint8_t obstacleColor;

    // Down-left
    for (uint8_t i = 1; i <= x && i <= y; i++) {
        uint8_t obstacleColor = getPieceColor(pieces[x - i][y - i]);
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
        uint8_t obstacleColor = getPieceColor(pieces[x - i][y + i]);
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
        uint8_t obstacleColor = getPieceColor(pieces[x + i][y - i]);
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
        uint8_t obstacleColor = getPieceColor(pieces[x + i][y + i]);
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
static void listQueenMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
    listRookMoves(gameState, moveList, x, y);
    listBishopMoves(gameState, moveList, x, y);
};

// List king moves at coordinate (x, y) and update moveList.
static void listKingMoves(GameState* gameState, MoveList* moveList, uint8_t x, uint8_t y) {
    uint8_t** pieces = gameState -> pieces;
    uint8_t color = getPieceColor(pieces[x][y]);
    if (x > 0) {
        if (color != getPieceColor(pieces[x - 1][y])) {
            addMove(moveList, x, y, x - 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(pieces[x - 1][y - 1])) {
                addMove(moveList, x, y, x - 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(pieces[x - 1][y + 1])) { 
                addMove(moveList, x, y, x - 1, y + 1, 0);
            }
        }
    }
    if (y > 0) {
        if (color != getPieceColor(pieces[x][y - 1])) {
            addMove(moveList, x, y, x, y - 1, 0);
        }
    }
    if (y < 7) {
        if (color != getPieceColor(pieces[x][y + 1])) {
            addMove(moveList, x, y, x, y + 1, 0);
        }
    }
    if (x < 7) {
        if (color != getPieceColor(pieces[x + 1][y])) {
            addMove(moveList, x, y, x + 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(pieces[x + 1][y - 1])) {
                addMove(moveList, x, y, x + 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(pieces[x + 1][y + 1])) { 
                addMove(moveList, x, y, x + 1, y + 1, 0);
            }
        }
    }
};
