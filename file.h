#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include "buffer.h"

int writeBufferToFile(Buffer, char [], char []);
int readFileToBuffer(Buffer *, char [], char []);
void loadFileInBuffer(Buffer *buffer, FILE *file);

#endif
