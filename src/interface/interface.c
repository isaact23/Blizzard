#include "interface/interface.h"

static bool debugMode = false;

/* First command sent from frontend. Switch to UCI mode (Universal Chess Interface).
 * Since that is this engine's only mode, simply identify self to the frontend. */
void uci() {
    info("Received UCI command");
    sendCommand("id name Blizzard");
    sendCommand("id author Isaac Thompson");

    sendCommand("option name Move Overhead type spin default 10 min 0 max 5000");
    sendCommand("option name Threads type spin default 1 min 1 max 128");
    sendCommand("option name Hash type spin default 16 min 1 max 4096"); // Allowed RAM usage in MB
    sendCommand("option name MultiPV type spin default 1 min 1 max 500");
    sendCommand("option name SyzygyPath type string default <empty>");
    sendCommand("option name UCI_ShowWDL type check default false");


    sendCommand("uciok");

    //sendCommand("copyprotection checking");
    //sendCommand("copyprotection ok");
    //sendCommand("registration checking");
    //sendCommand("registration ok");
}

/* Enable/disable debug mode */
void debug(bool value) {
    info("Set debug mode to %s", value);
    debugMode = value;
}

/* Wellness check */
void isready() {
    info("Blizzard is ready");
    sendCommand("readyok");
}

/* Set engine parameters */
void setoption(char* name, char* value) {
    info("Setting parameter %s to %s", name, value);
}

/* Start a new game. */
void ucinewgame() {
    info("Starting new game");
}

/* Set the chess board position. */
void position(char* fen, char** moves, int moveCount) {
    info("Setting position");
    setPosition(fen, moves, moveCount);
}

/* Start search. */
void go() {
    info("Starting search");
    startSearch();
}

/* Stop searching. */
void stop() {
    info("Stopping search");
    stopSearch();
    sendCommand("bestmove %s", getBestMove());
}

/* Called when the user makes the predicted move. Switch from pondering to searching 
 * with the same search tree. */
void ponderhit() {
    info("Ponder hit");
}

/* Clean up memory and stop the program. */
void quit() {
    info("Quitting Blizzard");
    shutdown();
}
