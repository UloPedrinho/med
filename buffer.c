/* * TODO [0/2] */
/*   - [ ] add line to buffer */
/*   - [ ] destroy buffer for free memory!! */
/*   - [ ] edit */
/*     save in same space redimensioning */
/*     the buffer or something ?? */
/*     - [ ] list lines, page by page */
/*     - [ ] print line to be edit */
/*     - [ ] save line */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE_LIMIT 100000 /* char */

struct BUFFER {
  int max_size;
  int current_size;
  char *data;
};

struct BUFFER createBuffer(int);
int addCharToBuffer(struct BUFFER *, char);

/* NOTE: debug functions */
void printBuffer(struct BUFFER);
void fillBuffer(struct BUFFER *);

int main() {

  char *pointer;
  struct BUFFER b;

  b = createBuffer(6);

  pointer = b.data;

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, 'a')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, 'n')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, 's')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, 'i')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, '+')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, '!')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */

  /* printf("r:%d\n", addCharToBuffer(&b, '@')); */

  /* printf("ms:%d, cs:%d\n", b.max_size, b.current_size); */



  /* printf("--------------\n"); */

  /* printf("1:%c\n", *b.data); */
  /* pointer++; */

  /* printf("2:%c\n", *pointer); */

  /* pointer++; */

  /* printf("3:%c\n", *pointer); */

  /* pointer++; */

  /* printf("4:%c\n", *pointer); */

  /* pointer++; */

  /* printf("5:%c\n", *pointer); */

  /* pointer++; */

  /* printf("6:%c\n", *pointer); */

  /* pointer++; */

  /* printf("7:%c\n", *pointer); */

  free(b.data);

}

/* Returns a new buffer with max size 'size. */
struct BUFFER createBuffer(int size){
  struct BUFFER b;
  b.max_size = size;
  b.current_size = 0;
  b.data = (char *)malloc(sizeof(char)*size);
  return b;
}

/* Add a char to buffer */
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

/* void fillBuffer(struct BUFFER *b, char data[]){ */
/*   int counter; */
/*   char *p; */
/*   p = b->data; */
/*   if (b->current_size < b->max_size){ */
    
/*   } */
