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
}

// Send a command to the frontend.
void sendCommand(char* command) {
    fprintf(stdout, command);
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