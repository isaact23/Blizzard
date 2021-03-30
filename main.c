#include "main.h"
#include "gameState.h"
#include "printHelper.h"

// Run the chess program.
int main() {
    printHeader();
    GameState* state = openingGameState();
    printGameState(state);
    freeGameState(state);
}
