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
  
  char* name;
  uint8_t type;

} Column;

typedef struct{
  
  void** fields;

} Row;


typedef struct{
  
  Column* Columns;
  Size colSize;
  
  Row* rows;
  Size rowSize;

} Table;

typedef struct database_t{

  char name[256];

  Table* tables;
  size_t numTables;


} Database;

#endif
