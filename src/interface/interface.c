#include "interface/interface.h"

static bool debugMode = false;

/* First command sent from frontend. Switch to UCI mode (Universal Chess Interface).
 * Since that is this engine's only mode, simply identify self to the frontend. */
void uci() {
    fprintf(stderr, "Received UCI command\n");
    sendCommand("id name Blizzard\n");
    sendCommand("id author Isaac Thompson\n");
    sendCommand("uciok\n");

    // Set engine to start position
    startPosition();

    //sendCommand("copyprotection checking\n");
    //sendCommand("copyprotection ok\n");
    //sendCommand("registration checking\n");
    //sendCommand("registration ok\n");
}

/* Enable/disable debug mode */
void debug(bool value) {
    fprintf(stderr, "Set debug mode to %s\n", value);
    debugMode = value;
}

/* Wellness check */
void isready() {
    fprintf(stderr, "Blizzard is ready\n");
    sendCommand("readyok\n");
}

/* Set engine parameters */
void setoption(char* name, char* value) {
    fprintf(stderr, "Setting parameter %s to %s\n", name, value);
}

/* Start a new game. */
void ucinewgame() {
    fprintf(stderr, "Starting new game\n");
}

/* Set the chess board position. */
void position(bool startPos, char* fen, char** moves, int moveCount) {
    fprintf(stderr, "Setting position\n");
    if (startPos) {
        startPosition();
    } else {
        setPosition(fen);
    }
}

/* Start search. */
void go(SearchSettings* settings) {
    fprintf(stderr, "Starting search\n");
}

/* Stop searching. */
void stop() {
    fprintf(stderr, "Stopping search\n");
}

/* Called when the user makes the predicted move. Switch from pondering to searching 
 * with the same search tree. */
void ponderhit() {
    fprintf(stderr, "Ponder hit\n");
}

/* Clean up memory and stop the program. */
void quit() {
    fprintf(stderr, "Quitting Blizzard\n");
}