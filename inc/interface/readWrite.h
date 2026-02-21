#ifndef __READ_WRITE_H__
#define __READ_WRITE_H__

#include <stdio.h>
#include <string.h>
#include "error.h"
#include "interface.h"
#include "searchSettings.h"
#include "split.h"

#define BUF_SIZE 512

// Send a command to the frontend.
void sendCommand(char* command, ...);

#endif
