#include "buffer.h"
#include "container.h"
#include <stdlib.h>


struct Container;

long countBufferLines(Buffer buffer){
  int counter;
  long lines;
  char *pointer;

  lines = 0;
  pointer = buffer.data;
  for (counter=0; counter<buffer.current_size; counter++) {
    if(*pointer == '\n'){
      lines++;
    }
    pointer++;
  }
  return lines;
}

void setBufferLines(Container *container, long lines){
  long counter;
  long start;
  long end;
  long line_number;

  container->lines = malloc(sizeof(Line)*lines);

  line_number = 0;
  start = 0;
  end = 0;
  for (counter=0; counter<container->buffer.current_size; counter++) {
    if(*(container->buffer.data+counter) == '\n'){
      container->lines[line_number].end = counter;
      line_number++;
      container->lines[line_number].start = counter+1;
    }
  }
  container->number_of_lines = line_number;
}
