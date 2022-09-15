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
	
	void** field;

} Column;


typedef struct{
	
	char* name;

  Column* columns;
  Memory colMem;
		
  Memory fieldsMem;

} Table;


typedef struct{

  char* name;

  Table* tables;
  Memory tableMem;

} Database;


#endif
