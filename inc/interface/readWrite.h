#ifndef __READ_WRITE_H__
#define __READ_WRITE_H__

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "interface/readWrite.h"
#include "interface.h"
#include "searchSettings.h"
#include "split.h"

#define BUF_SIZE 512

#define SWITCH_OUTPUTS

#ifdef SWITCH_OUTPUTS
#define COMMAND_OUTPUT stderr
#define DEBUG_OUTPUT stdout
#else
#define COMMAND_OUTPUT stdout
#define DEBUG_OUTPUT stderr
#endif

// Send a command to the frontend.
void sendCommand(char* command, ...);

void fatalError(char* message, ...);
void error(char* message, ...);
void info(char* message, ...);

#endif
