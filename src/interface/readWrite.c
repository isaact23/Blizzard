#include "readWrite.h"

// Process a Universal Chess Interface (UCI) command.
static void evaluate(WordNode* command) {
    while (command != NULL) {
        printf("%s\n", command -> word);
        command = command -> next;
    }
}

// Send a command to the frontend.
void sendCommand(char* command) {
    printf(command);
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