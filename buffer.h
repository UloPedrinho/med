#ifndef _BUFFER_H
#define _BUFFER_H

typedef struct {
  int max_size;
  int current_size;
  char *data;
} Buffer;

int getStringLength(char []);
Buffer createBuffer(int);
void destroyBuffer(Buffer);
int addCharToBuffer(Buffer *, char);
int addStringToBuffer(Buffer *, char []);

#endif
