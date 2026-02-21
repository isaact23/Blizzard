#include "error.h"

void fatalError(char* message, ...) {
    char buf[512];
    va_list args;
    va_start(args, message);
    vsnprintf(buf, 512, message, args);
    fprintf(stderr, "[Fatal Error] %s\n", buf);
    va_end(args);
}

void error(char* message, ...) {
    char buf[512];
    va_list args;
    va_start(args, message);
    vsnprintf(buf, 512, message, args);
    fprintf(stderr, "[Error] %s\n", buf);
    va_end(args);
}

void info(char* message, ...) {
    char buf[512];
    va_list args;
    va_start(args, message);
    vsnprintf(buf, 512, message, args);
    fprintf(stderr, "[Info] %s\n", buf);
    va_end(args);
}