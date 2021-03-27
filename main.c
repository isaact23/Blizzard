#include "main.h"
#include "gameState.h"
#include "printHelper.h"

// Run the chess program.
int main() {
    printHeader();
    gameState* state = openingBoard();
    printBoard(state);
    freeBoard(state);
    printf("Board created and freed");
}
