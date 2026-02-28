#include "engine/moveLister.h"

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

static bool isAttackedBy(GameState* state, uint8_t x, uint8_t y, uint8_t turn) {
    if (turn == WHITE) {
        // Knight check
        if (x > 1 && y > 0 && state -> pieces[x - 2][y - 1] == WN) return true;
        if (x > 0 && y > 1 && state -> pieces[x - 1][y - 2] == WN) return true;
        if (x < 6 && y > 0 && state -> pieces[x + 2][y - 1] == WN) return true;
        if (x < 7 && y > 1 && state -> pieces[x + 1][y - 2] == WN) return true;
        if (x > 1 && y < 7 && state -> pieces[x - 2][y + 1] == WN) return true;
        if (x > 0 && y < 6 && state -> pieces[x - 1][y + 2] == WN) return true;
        if (x < 6 && y < 7 && state -> pieces[x + 2][y + 1] == WN) return true;
        if (x < 7 && y < 6 && state -> pieces[x + 1][y + 2] == WN) return true;

        // Rook/queen check
        // West
        for (int i = x - 1; i >= 0; i--) {
            if (state -> pieces[i][y] == WR || state -> pieces[i][y] == WQ) return true;
            if (state -> pieces[i][y] != EMPTY) break;
        }
        // East
        for (int i = x + 1; i <= 7; i++) {
            if (state -> pieces[i][y] == WR || state -> pieces[i][y] == WQ) return true;
            if (state -> pieces[i][y] != EMPTY) break;
        }
        // South
        for (int j = y - 1; j >= 0; j--) {
            if (state -> pieces[x][j] == WR || state -> pieces[x][j] == WQ) return true;
            if (state -> pieces[x][j] != EMPTY) break;
        }
        // North
        for (int j = y + 1; j <= 7; j++) {
            if (state -> pieces[x][j] == WR || state -> pieces[x][j] == WQ) return true;
            if (state -> pieces[x][j] != EMPTY) break;
        }

        // Bishop/queen check
        // Southwest
        for (int i = 1; i <= 7; i++) {
            if (x - i < 0 || y - i < 0) break;
            if (state -> pieces[x - i][y - i] == WB || state -> pieces[x - i][y - i] == WQ) return true;
            if (state -> pieces[x - i][y - i] == EMPTY) break;
        }
        // Southeast
        for (int i = 1; i <= 7; i++) {
            if (x + i > 7 || y - i < 0) break;
            if (state -> pieces[x + i][y - i] == WB || state -> pieces[x + i][y - i] == WQ) return true;
            if (state -> pieces[x + i][y - i] == EMPTY) break;
        }
        // Northwest
        for (int i = 1; i <= 7; i++) {
            if (x - i < 0 || y + i > 7) break;
            if (state -> pieces[x - i][y + i] == WB || state -> pieces[x - i][y + i] == WQ) return true;
            if (state -> pieces[x - i][y + i] == EMPTY) break;
        }
        // Northeast
        for (int i = 1; i <= 7; i++) {
            if (x + i > 7 || y + i > 7) break;
            if (state -> pieces[x + i][y + i] == WB || state -> pieces[x + i][y + i] == WQ) return true;
            if (state -> pieces[x + i][y + i] == EMPTY) break;
        }

        // Pawn check
        if (y > 0) {
            if (x > 0) {
                if (state -> pieces[x - 1][y - 1] == WP) return true;
            }
            if (x < 7) {
                if (state -> pieces[x + 1][y - 1] == WP) return true;
            }
        }

        // King check
        if (x > 0) {
            if (state -> pieces[x - 1][y] == WK) return true;
            if (y > 0) {
                if (state -> pieces[x - 1][y - 1] == WK) return true;
            }
            if (y < 7) {
                if (state -> pieces[x - 1][y + 1] == WK) return true;
            }
        }
        if (y > 0) {
            if (state -> pieces[x][y - 1] == WK) return true;
        }
        if (y < 7) {
            if (state -> pieces[x][y + 1] == WK) return true;
        }
        if (x < 7) {
            if (state -> pieces[x + 1][y] == WK) return true;
            if (y > 0) {
                if (state -> pieces[x + 1][y - 1] == WK) return true;
            }
            if (y < 7) {
                if (state -> pieces[x + 1][y + 1] == WK) return true;
            }
        }
    }
    else {
        // Knight check
        if (x > 1 && y > 0 && state -> pieces[x - 2][y - 1] == BN) return true;
        if (x > 0 && y > 1 && state -> pieces[x - 1][y - 2] == BN) return true;
        if (x < 6 && y > 0 && state -> pieces[x + 2][y - 1] == BN) return true;
        if (x < 7 && y > 1 && state -> pieces[x + 1][y - 2] == BN) return true;
        if (x > 1 && y < 7 && state -> pieces[x - 2][y + 1] == BN) return true;
        if (x > 0 && y < 6 && state -> pieces[x - 1][y + 2] == BN) return true;
        if (x < 6 && y < 7 && state -> pieces[x + 2][y + 1] == BN) return true;
        if (x < 7 && y < 6 && state -> pieces[x + 1][y + 2] == BN) return true;

        // Rook/queen check
        // West
        for (int i = x - 1; i >= 0; i--) {
            if (state -> pieces[i][y] == BR || state -> pieces[i][y] == BQ) return true;
            if (state -> pieces[i][y] != EMPTY) break;
        }
        // East
        for (int i = x + 1; i <= 7; i++) {
            if (state -> pieces[i][y] == BR || state -> pieces[i][y] == BQ) return true;
            if (state -> pieces[i][y] != EMPTY) break;
        }
        // South
        for (int j = y - 1; j >= 0; j--) {
            if (state -> pieces[x][j] == BR || state -> pieces[x][j] == BQ) return true;
            if (state -> pieces[x][j] != EMPTY) break;
        }
        // North
        for (int j = y + 1; j <= 7; j++) {
            if (state -> pieces[x][j] == BR || state -> pieces[x][j] == BQ) return true;
            if (state -> pieces[x][j] != EMPTY) break;
        }

        // Bishop/queen check
        // Southwest
        for (int i = 1; i <= 7; i++) {
            if (x - i < 0 || y - i < 0) break;
            if (state -> pieces[x - i][y - i] == BB || state -> pieces[x - i][y - i] == BQ) return true;
            if (state -> pieces[x - i][y - i] == EMPTY) break;
        }
        // Southeast
        for (int i = 1; i <= 7; i++) {
            if (x + i > 7 || y - i < 0) break;
            if (state -> pieces[x + i][y - i] == BB || state -> pieces[x + i][y - i] == BQ) return true;
            if (state -> pieces[x + i][y - i] == EMPTY) break;
        }
        // Northwest
        for (int i = 1; i <= 7; i++) {
            if (x - i < 0 || y + i > 7) break;
            if (state -> pieces[x - i][y + i] == BB || state -> pieces[x - i][y + i] == BQ) return true;
            if (state -> pieces[x - i][y + i] == EMPTY) break;
        }
        // Northeast
        for (int i = 1; i <= 7; i++) {
            if (x + i > 7 || y + i > 7) break;
            if (state -> pieces[x + i][y + i] == BB || state -> pieces[x + i][y + i] == BQ) return true;
            if (state -> pieces[x + i][y + i] == EMPTY) break;
        }

        // Pawn check
        if (y > 0) {
            if (x > 0) {
                if (state -> pieces[x - 1][y - 1] == BP) return true;
            }
            if (x < 7) {
                if (state -> pieces[x + 1][y - 1] == BP) return true;
            }
        }

        // King check
        if (x > 0) {
            if (state -> pieces[x - 1][y] == BK) return true;
            if (y > 0) {
                if (state -> pieces[x - 1][y - 1] == BK) return true;
            }
            if (y < 7) {
                if (state -> pieces[x - 1][y + 1] == BK) return true;
            }
        }
        if (y > 0) {
            if (state -> pieces[x][y - 1] == BK) return true;
        }
        if (y < 7) {
            if (state -> pieces[x][y + 1] == BK) return true;
        }
        if (x < 7) {
            if (state -> pieces[x + 1][y] == BK) return true;
            if (y > 0) {
                if (state -> pieces[x + 1][y - 1] == BK) return true;
            }
            if (y < 7) {
                if (state -> pieces[x + 1][y + 1] == BK) return true;
            }
        }
    }

    return false;
}

static void addMoveIfValid(GameState* oldState, MoveList* moveList, uint8_t from_x, uint8_t from_y, uint8_t to_x, uint8_t to_y, uint8_t promotion) {

    GameState* state = copyGameState(oldState);
    Move move;
    move.from_x = from_x;
    move.from_y = from_y;
    move.to_x = to_x;
    move.to_y = to_y;
    move.promotion = promotion;
    applyMoveToGameState(state, &move);

    // Find king
    int x = 0;
    int y = 0;
    bool found = false;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            if (state -> pieces[x][y] == WK && oldState -> turn == WHITE) {
                found = true;
                break;
            }
            if (state -> pieces[x][y] == BK && oldState -> turn == BLACK) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        error("Could not find king");
        goto END;
    }

    // If king is attacked by opponent in this position, invalidate the move.
    if (oldState -> turn == WHITE) {
        if (isAttackedBy(state, x, y, BLACK)) goto END;
    }
    if (oldState -> turn == BLACK) {
        if (isAttackedBy(state, x, y, WHITE)) goto END;
    }

    // All checks passed, add the move to the list of valid moves.
    addMove(moveList, from_x, from_y, to_x, to_y, promotion);

END:
    freeGameState(state);
}

// List pawn moves at coordinate (x, y) and update moveList.
static void listPawnMoves(GameState* state, MoveList* moveList, uint8_t x, uint8_t y) {
    if (state -> pieces[x][y] == WP) {
        // Move forward 1
        if (y < 7 && state -> pieces[x][y + 1] == EMPTY) {
            addMoveIfValid(state, moveList, x, y, x, y + 1, 0);
            // Promotion
            if (y == 6) {
                addMoveIfValid(state, moveList, x, 6, x, 7, QUEEN);
                addMoveIfValid(state, moveList, x, 6, x, 7, ROOK);
                addMoveIfValid(state, moveList, x, 6, x, 7, BISHOP); 
                addMoveIfValid(state, moveList, x, 6, x, 7, KNIGHT); 
            }
        }
        // Move forward 2
        if (y == 1 && state -> pieces[x][2] == EMPTY && state -> pieces[x][3] == EMPTY) {
            addMoveIfValid(state, moveList, x, 1, x, 3, 0);
        }
        // Capture (left)
        if (x > 0 && y < 7 && getPieceColor(state -> pieces[x - 1][y + 1]) == BLACK) {
            addMoveIfValid(state, moveList, x, y, x - 1, y + 1, 0);
            // Capture promotion (left)
            if (y == 6) {
                addMoveIfValid(state, moveList, x, 6, x - 1, 7, QUEEN);
                addMoveIfValid(state, moveList, x, 6, x - 1, 7, ROOK);
                addMoveIfValid(state, moveList, x, 6, x - 1, 7, BISHOP);
                addMoveIfValid(state, moveList, x, 6, x - 1, 7, KNIGHT);
            }
        }
        // Capture (right)
        if (x < 7 && y < 7 && getPieceColor(state -> pieces[x + 1][y + 1]) == BLACK) {
            addMoveIfValid(state, moveList, x, y, x + 1, y + 1, 0);
            // Capture promotion (right)
            if (y == 6) {
                addMoveIfValid(state, moveList, x, 6, x + 1, 7, QUEEN);
                addMoveIfValid(state, moveList, x, 6, x + 1, 7, ROOK);
                addMoveIfValid(state, moveList, x, 6, x + 1, 7, BISHOP);
                addMoveIfValid(state, moveList, x, 6, x + 1, 7, KNIGHT);
            }
        }
        // En passant
        uint8_t passantFile = state -> enPassantFile;
        if (passantFile < 8 && y == 4) {
            if (x > 0 && passantFile == x - 1 && state -> pieces[x - 1][5] == EMPTY) {
                addMoveIfValid(state, moveList, x, 4, x - 1, 5, 0);
            }
            if (x < 7 && passantFile == x + 1 && state -> pieces[x + 1][5] == EMPTY) {
                addMoveIfValid(state, moveList, x, 4, x + 1, 5, 0);
            }
        }
    }
    else if (state -> pieces[x][y] == BP) {
        // Move forward 1
        if (y > 0 && state -> pieces[x][y - 1] == EMPTY) {
            addMoveIfValid(state, moveList, x, y, x, y - 1, 0);
            // Promotion
            if (y == 1) {
                addMoveIfValid(state, moveList, x, 1, x, 0, QUEEN);
                addMoveIfValid(state, moveList, x, 1, x, 0, ROOK);
                addMoveIfValid(state, moveList, x, 1, x, 0, BISHOP); 
                addMoveIfValid(state, moveList, x, 1, x, 0, KNIGHT); 
            }
        }
        // Move forward 2
        if (y == 6 && state -> pieces[x][5] == EMPTY && state -> pieces[x][4] == EMPTY) {
            addMoveIfValid(state, moveList, x, 6, x, 4, 0);
        }
        // Capture (left)
        if (x > 0 && y > 0 && getPieceColor(state -> pieces[x - 1][y - 1]) == WHITE) {
            addMoveIfValid(state, moveList, x, y, x - 1, y - 1, 0);
            // Capture promotion (left)
            if (y == 1) {
                addMoveIfValid(state, moveList, x, 1, x - 1, 0, QUEEN);
                addMoveIfValid(state, moveList, x, 1, x - 1, 0, ROOK);
                addMoveIfValid(state, moveList, x, 1, x - 1, 0, BISHOP);
                addMoveIfValid(state, moveList, x, 1, x - 1, 0, KNIGHT);
            }
        }
        // Capture (right)
        if (x < 7 && y > 0 && getPieceColor(state -> pieces[x + 1][y - 1]) == WHITE) {
            addMoveIfValid(state, moveList, x, y, x + 1, y - 1, 0);
            // Capture promotion (right)
            if (y == 1) {
                addMoveIfValid(state, moveList, x, 1, x + 1, 0, QUEEN);
                addMoveIfValid(state, moveList, x, 1, x + 1, 0, ROOK);
                addMoveIfValid(state, moveList, x, 1, x + 1, 0, BISHOP);
                addMoveIfValid(state, moveList, x, 1, x + 1, 0, KNIGHT);
            }
        }
        // En passant
        uint8_t passantFile = state -> enPassantFile;
        if (passantFile < 8 && y == 3) {
            if (x > 0 && passantFile == x - 1 && state -> pieces[x - 1][2] == EMPTY) {
                addMoveIfValid(state, moveList, x, 3, x - 1, 2, 0);
            }
            if (x < 7 && passantFile == x + 1 && state -> pieces[x + 1][2] == EMPTY) {
                addMoveIfValid(state, moveList, x, 3, x + 1, 2, 0);
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
                addMoveIfValid(state, moveList, x, y, x - 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(state -> pieces[x - 1][y + 2]) != color) {
                addMoveIfValid(state, moveList, x, y, x - 1, y + 2, 0);
            }
        }
        if (x > 1) {
            if (y > 0) {
                if (getPieceColor(state -> pieces[x - 2][y - 1]) != color) {
                    addMoveIfValid(state, moveList, x, y, x - 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(state -> pieces[x - 2][y + 1]) != color) {
                    addMoveIfValid(state, moveList, x, y, x - 2, y + 1, 0);
                }
            }
        }
    }
    if (x < 7) {
        if (y > 1) {
            if (getPieceColor(state -> pieces[x + 1][y - 2]) != color) {
                addMoveIfValid(state, moveList, x, y, x + 1, y - 2, 0);
            }
        }
        if (y < 6) {
            if (getPieceColor(state -> pieces[x + 1][y + 2]) != color) {
                addMoveIfValid(state, moveList, x, y, x + 1, y + 2, 0);
            }
        }
        if (x < 6) {
            if (y > 0) {
                if (getPieceColor(state -> pieces[x + 2][y - 1]) != color) {
                    addMoveIfValid(state, moveList, x, y, x + 2, y - 1, 0);
                }
            }
            if (y < 7) {
                if (getPieceColor(state -> pieces[x + 2][y + 1]) != color) {
                    addMoveIfValid(state, moveList, x, y, x + 2, y + 1, 0);
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
            addMoveIfValid(state, moveList, x, y, i, y, 0);
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
            addMoveIfValid(state, moveList, x, y, i, y, 0);
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
            addMoveIfValid(state, moveList, x, y, x, i, 0);
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
            addMoveIfValid(state, moveList, x, y, x, i, 0);
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
            addMoveIfValid(state, moveList, x, y, x - i, y - i, 0);
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
            addMoveIfValid(state, moveList, x, y, x - i, y + i, 0);
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
            addMoveIfValid(state, moveList, x, y, x + i, y - i, 0);
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
            addMoveIfValid(state, moveList, x, y, x + i, y + i, 0);
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
            addMoveIfValid(state, moveList, x, y, x - 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(state -> pieces[x - 1][y - 1])) {
                addMoveIfValid(state, moveList, x, y, x - 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(state -> pieces[x - 1][y + 1])) { 
                addMoveIfValid(state, moveList, x, y, x - 1, y + 1, 0);
            }
        }
    }
    if (y > 0) {
        if (color != getPieceColor(state -> pieces[x][y - 1])) {
            addMoveIfValid(state, moveList, x, y, x, y - 1, 0);
        }
    }
    if (y < 7) {
        if (color != getPieceColor(state -> pieces[x][y + 1])) {
            addMoveIfValid(state, moveList, x, y, x, y + 1, 0);
        }
    }
    if (x < 7) {
        if (color != getPieceColor(state -> pieces[x + 1][y])) {
            addMoveIfValid(state, moveList, x, y, x + 1, y, 0);
        }
        if (y > 0) {
            if (color != getPieceColor(state -> pieces[x + 1][y - 1])) {
                addMoveIfValid(state, moveList, x, y, x + 1, y - 1, 0);
            }
        }
        if (y < 7) {
            if (color != getPieceColor(state -> pieces[x + 1][y + 1])) { 
                addMoveIfValid(state, moveList, x, y, x + 1, y + 1, 0);
            }
        }
    }

    // Castling
    if (x == 4) {
        if (y == 0) {
            if (state -> castleFlags & CAN_CASTLE_WHITE_KINGSIDE) {
                if (state -> pieces[5][0] == EMPTY && state -> pieces[6][0] == EMPTY) {
                    addMoveIfValid(state, moveList, 4, 0, 6, 0, 0);
                }
            }
            if (state -> castleFlags & CAN_CASTLE_WHITE_QUEENSIDE) {
                if (state -> pieces[2][0] == EMPTY && state -> pieces[3][0] == EMPTY) {
                    addMoveIfValid(state, moveList, 4, 0, 2, 0, 0);
                }
            }
        }
        else if (y == 7) {
            if (state -> castleFlags & CAN_CASTLE_BLACK_KINGSIDE) {
                if (state -> pieces[5][7] == EMPTY && state -> pieces[6][7] == EMPTY) {
                    addMoveIfValid(state, moveList, 4, 7, 6, 7, 0);
                }
            }
            if (state -> castleFlags & CAN_CASTLE_BLACK_QUEENSIDE) {
                if (state -> pieces[2][7] == EMPTY && state -> pieces[3][7] == EMPTY) {
                    addMoveIfValid(state, moveList, 4, 7, 2, 7, 0);
                }
            }
        }
    }
};
