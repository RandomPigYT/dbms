#ifndef PIGSQL_INCLUDE_H
#define PIGSQL_INCLUDE_H
  
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct{
  size_t size;
  size_t memory;
} Size;


void splitStr(const char* str, char** dest);


#endif
