#include "buffer.h"
#include "file.h"
#include "container.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Container *containers;
int number_of_containers;



int main(int argc, char *argv[])
{
  long counter;

  number_of_containers = 0;

  /* allocating memory for one container */
  containers = (Container *)malloc(sizeof(Container));
  addContainer(containers, number_of_containers);
  /* addContainer(containers, number_of_containers); */

  /* sleep(1); */

  /* containers = (Container *)realloc(containers, sizeof(Container)*2); */

  loadContainerFromFile(&containers[0], "a.txt");
  loadContainerFromFile(&containers[1], "b.txt");

  /* for (counter=0; counter<container.number_of_lines; counter++) { */
  /*   printf("l%03ld - start:%ld , end:%ld\n", counter, container.lines[counter].start, container.lines[counter].end); */
  /* } */

  for(counter=0; counter<number_of_containers; counter++){

    printf("FILE: %s\n", containers[counter].filename);
    printf("===================================================");
    printf("number of lines: %ld\n", containers[counter].number_of_lines);
    printf("max_size: %ld\n", containers[counter].buffer.max_size);
    printf("current_size: %ld\n", containers[counter].buffer.current_size);
    printf("data: %s\n", containers[counter].buffer.data);
  }
  /* printf("FILE: %s\n", container1.filename); */
  /* printf("==================================================="); */
  /* printf("number of lines: %ld\n", container.number_of_lines); */
  /* printf("max_size: %ld\n", container.buffer.max_size); */
  /* printf("current_size: %ld\n", container.buffer.current_size); */
  /* printf("data: %s\n", container.buffer.data); */



  /* printf("Lines: %ld", lines); */


  return 0;
}
