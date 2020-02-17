#include "container.h"
#include "buffer.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #include <stdio.h> */

struct Container;

long countBufferLines(Buffer buffer) {
  int counter;
  long lines;
  char *pointer;

  lines = 0;
  pointer = buffer.data;
  for (counter = 0; counter < buffer.current_size; counter++) {
    if (*pointer == '\n') {
      lines++;
    }
    pointer++;
  }
  if (counter != 0) {
    lines++;
  }
  return lines;
}

void setBufferLines(Container *container, long lines) {
  long counter;
  long start;
  long end;
  long line_number;

  container->lines = malloc(sizeof(Line) * lines);

  line_number = 0;
  start = 0;
  end = 0;
  if (lines != 0) {
    for (counter = 0; counter < container->buffer.current_size; counter++) {
      /* printf("counter:%2ld - char:%c\n", counter,
       * *(container->buffer.data+counter)); */
      if (*(container->buffer.data + counter) == '\n') {
        container->lines[line_number].end = counter;
        line_number++;
        container->lines[line_number].start = counter + 1;
      }
    }
    if (*(container->buffer.data + (counter-1)) != '\n'){
      container->lines[line_number].end = counter-1;
      line_number++;
    }

  }
  container->number_of_lines = line_number;
}

int loadContainerFromFile(Container *container, char filename[]) {
  FILE *fp;
  int success;
  fp = fopen(filename, "r");
  if (fp != NULL) {
    container->filename = (char *)malloc(sizeof(char) * strlen(filename));
    container->filename = filename;
    loadFileInBuffer(&container->buffer, fp);
    setBufferLines(container, countBufferLines(container->buffer));
    success = 1;
    fclose(fp);
  } else {
    success = 0;
  }
  return success;
}

/* Allocate memory for new contaire next to last. */
/* Return container position in array Containers */
int addContainer(Container *containers, int number_of_containers){
  HERE!!!!!!!!!!!
    number_of_containers++;
    containers = (Container *)realloc(containers, sizeof(Container)*number_of_containers);

  return number_of_containers;
}



/* void destroyContainer(Container *container){ */

/* } */
