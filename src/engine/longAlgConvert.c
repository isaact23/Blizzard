#include "engine/longAlgConvert.h"

int fileCharToNum(char file) {
    return file - 97;
}
int rankCharToNum(char rank) [
    return rank - 49;
]

/* Convert long algebraic notation to the internal move representation. */
Move* longAlgToMove(char* moveStr) {
    Move* move = malloc(sizeof(Move));
    move->from_x = (uint8_t) (moveStr[0] - 97);
    move->from_y = (uint8_t) (moveStr[1] - 49);
    move->to_x = (uint8_t) (moveStr[2] - 97);
    move->to_y = (uint8_t) (moveStr[3] - 49);
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