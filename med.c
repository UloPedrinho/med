#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"
#include "file.h"

#define BUFFER_SIZE_LIMIT 100000 /* char,, TODO: here?? in buffer.c?? */
#define LINE_SIZE 1000           /* char */

/* * declarations */

/* edit text */
char* readLine(int);
int enterText(struct BUFFER *);
int isEndLine(char *);

/* print funcionts */
void printBufferNumbered(struct BUFFER);

/* NOTE: debug functions */
void printBuffer(struct BUFFER);
void fillBuffer(struct BUFFER *);

/* * main */
int main() {

  char *pointer;
  struct BUFFER b;

  b = createBuffer(664);
  pointer = b.data;

  enterText(&b);

  writeBufferToFile(b, "perrymason", "w");

  /* readFileToBuffer(&b, "perrymason", "r"); */

  printf("----\n");

  printBufferNumbered(b);
  /* printBuffer(b); */

  destroyBuffer(b);
}

/* * Edit functions */

/*  */
char* readLine(int size){
  int counter;
  int c;
  char *l;
  l = (char*)malloc(sizeof(char)*size);
  counter =0;
  c=getchar();
  while(c!='\n'){
    *(l+counter)=c;
    counter++;
    c=getchar();
  }
  *(l+counter)='\n';
  *(l+counter+1)='\0';
  return l;
}

/*  */
int isEndLine(char *line){
  int success;
  if (*line=='.' && *(line+1)=='\n')
    success = 1;
  else
    success = 0;
  return success;
}

/* Loop for enter text. End with ^.\n */
/* Write to buffer each line.*/
/* Return 0 if buffer overflow, if not 1 success */
int enterText(struct BUFFER *b){
  char *line;
  int success;
  int last_was_newline;
  success = 1;
  last_was_newline = 0;
  while(last_was_newline!=1 && success!=0) {
    line=readLine(LINE_SIZE);
    last_was_newline = isEndLine(line);
    if (last_was_newline!=1) {
      success = addStringToBuffer(b, line);
    }
  }
  return success;
}

/* ***************** */
/* * print functions */
void printBufferNumbered(struct BUFFER buffer){
  int counter;
  int line;
  line = 1;
  printf("%d: ", line);
  line++;
  for (counter=0; counter<buffer.current_size; counter++) {
    if (*(buffer.data+counter) == '\n') {
      printf("\n%d: ", line);
      line++;
    }
    else
      printf("%c", *(buffer.data+counter));
  }
}

/* * Debug functions */
/* ***************** */
/* NOTE: debug functions */
void printBuffer(struct BUFFER b){
  int counter;
  char *p;
  p = b.data;
  for (counter=0; counter<b.current_size; counter++) {
    printf("%c", *p);
    p++;
  }
}







