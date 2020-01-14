#include <stdlib.h>
#include "buffer.h"

struct BUFFER;

/* Return string length */
int getStringLength(char s[]){
  int counter;
  counter = 0;
  while(s[counter]!= '\0')
    counter ++;
  return counter;
}

/* Returns a new buffer with max size 'size. */
struct BUFFER createBuffer(int size){
  struct BUFFER b;
  b.max_size = size;
  b.current_size = 0;
  b.data = (char *)malloc(sizeof(char)*size);
  return b;
}

/* Free buffer from memory. */
void destroyBuffer(struct BUFFER b){
  free(b.data);
}

/* Add a char to buffer. Return 1 if success, 0 if no capacity */
int addCharToBuffer(struct BUFFER *b, char c){
  int success;
  if(b->current_size < b->max_size) {
    *(b->data+b->current_size) = c;
    b->current_size++;
    success = 1;
  } else {
    success = 0;
  }
  return success;
}

/* Add a string to buffer. Return 1 if success, 0 if no capacity */
int addStringToBuffer(struct BUFFER *b, char s[]){
  int success;
  int counter;
  char *p;

  p = b->data;
  if((b->max_size - b->current_size) >= getStringLength(s)){
    for (counter=0; counter<getStringLength(s); counter++) {
      *(p+b->current_size) = s[counter];
      b->current_size++;
      success = 1;
    }
  } else {
    success = 0;
  }
  return success;
}
