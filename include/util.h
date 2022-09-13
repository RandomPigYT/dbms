#ifndef PIGSQL_INCLUDE_H
#define PIGSQL_INCLUDE_H
  
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>


#define expandArray(array, mem, type){  \
  if (mem.size == 0){  \
\
    array = malloc(10 * sizeof(type));  \
    mem.memory = 10;  \
  } \
\
  else if (mem.memory == 0){ \
\
    array = realloc(array, (2 * mem.size) * sizeof(type)); \
\
    mem.memory = 2 * mem.size;  \
  } \
}


typedef struct{
	
  size_t size;
  size_t memory;

} Memory;


// splitStr takes a pointer 'numWords' where it stores the number of tokens in
// the string
char** splitStr(char* str, char sep, size_t* numWords);
void freeSplitStr(char** ptr, size_t numWords);

void initStack();
void push(void* item);
void* pop();
void destroyStack();
size_t stackSize();

#endif
