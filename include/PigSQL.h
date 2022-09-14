#ifndef PIGSQL_H
#define PIGSQL_H

#include "util.h"
#include "structs.h"
#include "globals.h"
#include <stdint.h> 
#include <stddef.h>


// Function declerations

void createDb(const char* name);

void createTable(const char* name, char** columns, uint8_t* types, uint32_t numColumns);


#endif
