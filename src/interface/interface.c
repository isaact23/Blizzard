#include "interface.h"

static bool debugMode = false;

/* First command sent from frontend. Switch to UCI mode (Universal Chess Interface).
 * Since that is this engine's only mode, simply identify self to the frontend. */
void uci() {
    sendCommand("id name Blizzard\n");
    sendCommand("id author Isaac Thompson\n");
    sendCommand("uciok\n");
    sendCommand("copyprotection checking\n");
    sendCommand("copyprotection ok\n");
    sendCommand("registration checking\n");
    sendCommand("registration ok\n");
}

/* Enable/disable debug mode */
void debug(bool value) {
    debugMode = value;
}

/* Wellness check */
void isready() {
    sendCommand("readyok\n");
}

/* Set engine parameters */
void setoption(char* name, char* value) {

}