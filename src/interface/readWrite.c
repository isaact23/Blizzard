#include "interface/readWrite.h"

// Process a Universal Chess Interface (UCI) command.
static void evaluate(WordNode* command) {
    if (command == NULL) return;
    char* word1 = command -> word;

    if (strcmp(word1, "uci") == 0) {
        uci();
    }
    else if (strcmp(word1, "debug") == 0) {
        WordNode* command2 = command -> next;
        if (command2 == NULL) return;

        char* word2 = command2 -> next -> word;
        if (strcmp(word2, "on") == 0) {
            debug(true);
        }
        else if (strcmp(word2, "off") == 0) {
            debug(false);
        }
    }
    else if (strcmp(word1, "isready")) {
        isready();
    }
    else if (strcmp(word1, "setoption")) {
        info("Setting option not yet supported");
    }
    else if (strcmp(word1, "register")) {
        info("Register option not yet supported");
    }
    else if (strcmp(word1, "ucinewgame")) {
        ucinewgame();
    }
    /*else if (strcmp(word1, "position")) {
        WordNode* command2 = command -> next;
        char* 
    }*/
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
        WordNode* wordList = split(buffer);
        evaluate(wordList);
        freeWordList(wordList);
    }
}