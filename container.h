#ifndef _CONTAINER_H
#define _CONTAINER_H

#include "buffer.h"

typedef struct {
  long start;
  long end;
} Line;

typedef struct {
  Buffer buffer;
  Line *lines;
  long number_of_lines;
  int length_lines;
  int max_length_line;
  char *filename;
} Container;

long countBufferLines(Buffer buffer);
void setBufferLines(Container *container, long lines);

#endif
