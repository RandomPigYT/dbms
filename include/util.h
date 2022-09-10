#ifndef PIGSQL_INCLUDE_H
#define PIGSQL_INCLUDE_H
  
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


#define expandArray(array, mem, type){  \
  if(mem.size == 0){  \
\
    array = malloc(10 * sizeof(type));  \
    mem.memory = 10;  \
  } \
\
  else if(mem.memory == 0){ \
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


void splitStr(const char* str, char** dest);



#endif
