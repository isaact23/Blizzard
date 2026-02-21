#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>

void fatalError(char* message, ...);
void error(char* message, ...);
void info(char* message, ...);

#endif
