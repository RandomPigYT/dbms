#ifndef PIGSQL_STRUCTS_H
#define PIGSQL_STRUCTS_H
  
#include "util.h"
#include <stdint.h> 
#include <stddef.h>

enum types{

  INT,
  VAR_CHAR,
  TEXT,
  LOCAL_ID,
  FOREIGN_ID

};


typedef struct{
  
  void** fields;

} Row;


typedef struct{
  
  char* name;
  uint8_t type;

  Row rows;
  Memory rowMem;

} Column;


typedef struct{
  
  Column* Columns;
  Memory colMem;
  
} Table;


typedef struct{

  char* name;

  Table* tables;
  Memory tableMem;

} Database;


#endif
