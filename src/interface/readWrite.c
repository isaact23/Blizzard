#include "interface/readWrite.h"

// Process a Universal Chess Interface (UCI) command.
static void evaluate(char** keywords, int keywordCount) {
    if (keywords == NULL || keywordCount == 0) return;

    if (strcmp(keywords[0], "uci") == 0) {
        uci();
    }
    else if (strcmp(keywords[0], "debug") == 0) {
        if (keywordCount < 2) return;

        if (strcmp(keywords[1], "on") == 0) {
            debug(true);
        }
        else if (strcmp(keywords[1], "off") == 0) {
            debug(false);
        }
    }
    else if (strcmp(keywords[0], "isready") == 0) {
        isready();
    }
    else if (strcmp(keywords[0], "setoption") == 0) {
        info("Setting option not yet supported");
    }
    else if (strcmp(keywords[0], "register") == 0) {
        info("Register option not yet supported");
    }
    else if (strcmp(keywords[0], "ucinewgame") == 0) {
        ucinewgame();
    }
    else if (strcmp(keywords[0], "position") == 0) {
        if (keywordCount < 2) return;

        if (strcmp(keywords[1], "startpos") == 0) {
            startPosition();
        }
        else {
            
        }
    }
}

// Send a command to the frontend.
void sendCommand(char* command, ...) {
    char buf[512];
    va_list args;
    va_start(args, command);
    vsnprintf(buf, 512, command, args);
    fprintf(stdout, "%s\n", buf);
    va_end(args);
}

int main() {
    char buffer[BUF_SIZE];

    while (1) {
        fgets(buffer, BUF_SIZE, stdin);
        int keywordCount;
        char** keywords = split(buffer, &keywordCount);
        evaluate(keywords, keywordCount);
    }
}