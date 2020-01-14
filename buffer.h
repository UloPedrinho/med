#ifndef _BUFFER_H
#define _BUFFER_H

struct BUFFER {
  int max_size;
  int current_size;
  char *data;
};

int getStringLength(char []);
struct BUFFER createBuffer(int);
void destroyBuffer(struct BUFFER);
int addCharToBuffer(struct BUFFER *, char);
int addStringToBuffer(struct BUFFER *, char []);

#endif
