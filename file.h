#ifndef _FILE_H
#define _FILE_H

#include "buffer.h"

int writeBufferToFile(Buffer, char [], char []);
int readFileToBuffer(Buffer *, char [], char []);

#endif
