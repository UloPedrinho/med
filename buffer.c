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

int getStringLength(char []);

struct BUFFER createBuffer(int);
int addCharToBuffer(struct BUFFER *, char); /* TODO: needed? */
int addStringToBuffer(struct BUFFER *, char []);

/* NOTE: debug functions */
void printBuffer(struct BUFFER);
void fillBuffer(struct BUFFER *);

int main() {

  char *pointer;
  struct BUFFER b;

  b = createBuffer(4);

  pointer = b.data;

  /* printf("success: %d\n", addStringToBuffer(&b, "1234567890\n1234567890" )); */

  printf("success: %d\n", addStringToBuffer(&b, "1234"));


  printBuffer(b);

  free(b.data);

}

/*  */
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

/*  */
int addStringToBuffer(struct BUFFER *b, char s[]){
  int success;
  int counter;
  char *p;

  p = b->data;
  /* TODO: limit? +1/-1/0 */
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

/* void fillBuffer(struct BUFFER *b, char data[]){ */
/*   int counter; */
/*   char *p; */
/*   p = b->data; */
/*   if (b->current_size < b->max_size){ */
/*   } */

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
