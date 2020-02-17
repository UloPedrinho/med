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
  char *filename;
} Container;

long countBufferLines(Buffer buffer);
void setBufferLines(Container *container, long lines);
int loadContainerFromFile(Container *container, char filename[]);
int addContainer(Container *containers, int number_of_containers);

#endif
