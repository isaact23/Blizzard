#ifndef __SPLIT_H__
#define __SPLIT_H__

#include <stdlib.h>
#include <string.h>

struct _wordNode {
    char* word;
    struct _wordNode* next;
};
typedef struct _wordNode WordNode;

// Split a string at whitespaces and return a linked list of trimmed words.
WordNode* split(char* src);

// Free memory from a linked list of words.
void freeWordList(WordNode* wordList);

#endif
