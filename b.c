#include "buffer.h"
#include "file.h"
#include "container.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  Container container;
  FILE *fp;
  long counter;

  newContainerFromFile(&container, "deleteme");

  for (counter=0; counter<container.number_of_lines; counter++) {
    printf("l%03ld - start:%ld , end:%ld\n", counter, container.lines[counter].start, container.lines[counter].end);
  }

  printf("number of lines: %ld\n", container.number_of_lines);
  printf("max_size: %ld\n", container.buffer.max_size);
  printf("current_size: %ld\n", container.buffer.current_size);
  printf("data: %s\n", container.buffer.data);

  /* printf("Lines: %ld", lines); */


  return 0;
}

