#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "file.h"


/* TODO: return value */
/* Return 1 if success, 0 some error */
int writeBufferToFile(Buffer buffer, char filename[], char mode[]) {
  FILE * pointer_file;
  int success;
  success = 1;

  pointer_file = fopen(filename, mode);
  fwrite(buffer.data, sizeof(char), buffer.current_size, pointer_file);

  fclose(pointer_file);
}


/* TODO: to be deleted */
int readFileToBuffer(Buffer *buffer, char filename[], char mode[]){
  FILE * pointer_file;
  long counter;
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
  return counter;
}

/* TODO: return if file_size greater dan buffer max_size */
void loadFileInBuffer(Buffer *buffer, FILE *file){
  long file_size;
  char *text;

  /* get file size */
  fseek(file, 1, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  /* size memory */
  buffer->data = (char*)malloc(sizeof(char)*file_size);
  text = (char*)malloc(sizeof(char)*file_size);

  /* read file */
  fread(text, 1, file_size, file);

  /* set buffer data */
  buffer->current_size = file_size;
  memcpy(buffer->data, text, file_size);
}

