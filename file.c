#include <stdio.h>
#include "file.h"


/* TODO: return value */
/* Return 1 if success, 0 some error */
int writeBufferToFile(struct BUFFER buffer, char filename[], char mode[]) {
  FILE * pointer_file;
  int success;
  success = 1;

  pointer_file = fopen(filename, mode);

  fwrite(buffer.data, sizeof(char), buffer.current_size, pointer_file);

  fclose(pointer_file);
}

/* TODO: return value */
/*  */
int readFileToBuffer(struct BUFFER *buffer, char filename[], char mode[]){
  FILE * pointer_file;
  int counter;
  int success;
  int c;
  success = 1;
  pointer_file = fopen(filename, mode);
  counter = 0;
  while((c = fgetc(pointer_file))!=EOF) {
    addCharToBuffer(buffer, c);
    counter++;
  }
  buffer->current_size = counter;
  fclose(pointer_file);
}
