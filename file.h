#ifndef _FILE_H
#define _FILE_H

#include "buffer.h"

int writeBufferToFile(struct BUFFER, char [], char []);
int readFileToBuffer(struct BUFFER *, char [], char []);

#endif
