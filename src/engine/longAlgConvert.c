#include "engine/longAlgConvert.h"

int fileCharToNum(char file) {
    return file - 97;
}
int rankCharToNum(char rank) {
    return rank - 49;
}

/* Convert long algebraic notation to the internal move representation. */
Move* longAlgToMove(char* moveStr) {
    Move* move = malloc(sizeof(Move));
    move->from_x = (uint8_t) fileCharToNum(moveStr[0]);
    move->from_y = (uint8_t) rankCharToNum(moveStr[1]);
    move->to_x = (uint8_t) fileCharToNum(moveStr[2]);
    move->to_y = (uint8_t) rankCharToNum(moveStr[3]);

    if (moveStr[4] == '\0') {
        move->promotion = 0;
    }
    else if (moveStr[4] == 'q') {
        move->promotion = QUEEN;
    }
    else if (moveStr[4] == 'r') {
        move->promotion = ROOK;
    }
    else if (moveStr[4] == 'b') {
        move->promotion = BISHOP;
    }
    else if (moveStr[4] == 'n') {
        move->promotion = KNIGHT;
    }
    return move;
}