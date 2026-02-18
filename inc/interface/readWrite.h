#ifndef __READWRITE_H__
#define __READWRITE_H__

#include <stdio.h>
#include "split.h"

#define BUF_SIZE 512

// Send a command to the frontend.
void sendCommand(char* command);

#endif
