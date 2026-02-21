#include "interface/split.h"

static bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

// Split a string at whitespaces and return a linked list of trimmed words.
char** split(char* src, int* keywordCount) {
    int i = 0;
    int count = 0; // Word counter
    WordNode* head = NULL;
    WordNode* tail = NULL;

    while (src[i] != '\0') {
        // Find the start of the word
        while (isWhitespace(src[i])) i++;
        if (src[i] == '\0') break;
        int start = i;

        // Find the end of the word
        while (src[i] != '\0' && !isWhitespace(src[i])) i++;
        int end = i;

        // Copy the word into a buffer
        int length = end - start;
        char* word = malloc(sizeof(char) * length);
        strncpy(word, &src[start], length);
        word[length] = '\0';

        // Add the word to the linked list
        WordNode* node = malloc(sizeof(WordNode));
        node -> word = word;
        node -> next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail -> next = node;
            tail = node;
        }
        count++;
    }

    // Copy words from linked list to a pointer array
    char** keywords = malloc(sizeof(char*) * count);
    WordNode* cur = head;
    for (int i = 0; i < count; i++) {
        WordNode* prev = cur;
        cur = cur -> next;
        keywords[i] = prev -> word;
        free(prev);
    }
    
    *keywordCount = count;
    return keywords;
}

// Free memory from a linked list of words.
/*void freeWordList(WordNode* wordList) {
    WordNode* current = wordList;
    while (current != NULL) {
        WordNode* prev = current;
        current = current -> next;
        free(prev -> word);
        free(prev);
    }
}*/
