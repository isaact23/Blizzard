#include "engine/longAlgConvert.h"

int fileCharToNum(char file) {
    int res = file - 97;
    if (res < 0 || res > 7) {
        fatalError("Invalid file char %s\n", file);
    }
    return res;
}
int rankCharToNum(char rank) {
    int res = rank - 49;
    if (res < 0 || res > 7) {
        fatalError("Invalid rank char %s\n", rank);
    }
    return res;
}
char numToFileChar(int file) {
    if (file < 0 || file > 7) {
        fatalError("Invalid file number %d\n", file);
    }
    return file + 97;
}
char numToRankChar(int rank) {
    if (rank < 0 || rank > 7) {
        fatalError("Invalid rank number %d\n", rank);
    }
    return rank + 49;
}

/* Convert internal move representation to long algebraic notation. */
char* moveToLongAlg(Move* move) {
    char* longAlg = malloc(6 * sizeof(char));
    longAlg[0] = numToFileChar(move->from_x);
    longAlg[1] = numToRankChar(move->from_y);
    longAlg[2] = numToFileChar(move->to_x);
    longAlg[3] = numToRankChar(move->to_y);
    if (move->promotion) {
        switch(move->promotion) {
            case QUEEN: {longAlg[4] = 'q'; break;}
            case ROOK: {longAlg[4] = 'r'; break;}
            case BISHOP: {longAlg[4] = 'b'; break;}
            case KNIGHT: {longAlg[4] = 'n'; break;}
            default: {longAlg[4] = '\0'; break;}
        }
        longAlg[5] = '\0';
    } else {
        longAlg[4] = '\0';
    }
    return longAlg;
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