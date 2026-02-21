#include "engine/error.h"

void fatalError(char* message, ...) {
    char buf[512];
    snprintf(buf, 512, message, argptr);
    fprintf(stderr, "[Fatal Error] %s\n", buf);
}

void error(char* message) {
    char buf[512];
    snprintf(buf, 512, message, argptr);
    fprintf(stderr, "[Error] %s\n", buf);
}

void info(char* message) {
    char buf[512];
    snprintf(buf, 512, message, argptr);
    fprintf(stderr, "[Info] %s\n", buf);
}