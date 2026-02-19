#include "engine/longAlgConvert.h"

/* Convert long algebraic notation to the internal move representation. */
Move* longAlgToMove(char* move) {
    Move* move = malloc(sizeof(Move));
    move->from_x = (uint8_t) strtol(move[0]) - 97;
    move->from_y = (uint8_t) strtol(move[1]) - 1;
    move->to_x = (uint8_t) strtol(move[2]) - 97;
    move->to_y = (uint8_t) strtol(move[3]) - 1;
    if (move[4] == '\0') {
        move->promotion = 0;
    }
    else if (move[4] == 'q') {
        move->promotion = QUEEN;
    }
    else if (move[4] == 'r') {
        move->promotion = ROOK;
    }
    else if (move[4] == 'b') {
        move->promotion = BISHOP;
    }
    else if (move[4] == 'n') {
        move->promotion = KNIGHT;
    }
    return move;
}