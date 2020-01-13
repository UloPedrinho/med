
/* * TODO [2/5] */
/*   - [X] create/destroy buffer for free memory!! */
/*   - [X] add char/string to buffer */
/*   - [ ] write buffer to file */
/*   - [ ] load file to buffer */
/*     - [ ] test if file is greater than buffer max size */
/*   - [ ] edit */
/*     save in same space redimensioning */
/*     the buffer or something ?? */
/*     - [ ] enter text */
/*       - [ ] end with '.' like in ed (?) */
/*         - [ ] better something more elaborated like vi? !q */
/*         - [ ] last newline must be removed (?) */
/*     - [ ] list lines, page by page */
/*     - [ ] print line to be edit */
/*     - [ ] save line */

/* * BUGS [0/1] */
/*   - [ ] reaLine() have no memory limit */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE_LIMIT 100000 /* char */
#define LINE_SIZE 1000           /* char */

struct BUFFER {
  int max_size;
  int current_size;
  char *data;
};

/* Buffer functions. */
int getStringLength(char []);
struct BUFFER createBuffer(int);
void destroyBuffer(struct BUFFER);
int addCharToBuffer(struct BUFFER *, char); /* TODO: needed? */
int addStringToBuffer(struct BUFFER *, char []);

/* edit text */
char* readLine(int);
int enterText(struct BUFFER *);

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

  printf("----\n");

  printBuffer(b);

  destroyBuffer(b);
}

/* * Buffer functions */

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

/* * Edit functions */
/*  */
/* TODO */
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

/* * Debug functions */

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
