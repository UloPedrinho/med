#include "../buffer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void loadBuffer(Buffer *buffer);
void loadFileInBuffer(Buffer *buffer, FILE *file);
long countBufferLines(Buffer buffer);

typedef struct {
  int start;
  int end;
} Line;

typedef struct {
  Buffer buffer;
  Line **lines;
  int length_lines;
  int max_length_line;
  char *filename;
} Container;


int main(int argc, char *argv[])
{
  Container container;
  FILE *fp;
  long lines;

  fp=fopen("b.c", "r");

  loadFileInBuffer(&container.buffer, fp);

  lines = countBufferLines(container.buffer);

  printf("max_size: %d\n", container.buffer.max_size);
  printf("current_size: %d\n", container.buffer.current_size);
  printf("data: %s\n", container.buffer.data);

  printf("Lines: %ld", lines);

  fclose(fp);
  return 0;
}

void loadFileInBuffer(Buffer *buffer, FILE *file){
  long file_size;
  char *text;

  /* get file size */
  fseek(file, 1, SEEK_END);
  file_size = ftell(file);
  fseek(file, 1, SEEK_SET);

  /* size memory */
  buffer->data = (char*)malloc(sizeof(char)*file_size);
  text = (char*)malloc(sizeof(char)*file_size);

  /* read file */
  fread(text, 1, file_size, file);

  /* set buffer data */
  buffer->current_size = file_size;
  memcpy(buffer->data, text, file_size);
}

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
