#include "../../../include/PigSQL.h"
#include <string.h>


#define currentTable database.tables[database.tableMem.size]


void setNames(char** columns, uint32_t numColumns){
	

	for(uint32_t i = 0; i < numColumns; i++){
		
		currentTable.columns[i].name = malloc(strlen(columns[i]) + 1);
		strcpy(currentTable.columns[i].name, columns[i]);
	}

}


void initColumns(uint32_t numColumns, uint8_t* types){

	for(uint32_t i = 0; i < numColumns; i++){

		// Set column types
		currentTable.columns[i].type = types[i];
		
		// Initialize column memory record
		currentTable.columns[i].field = NULL;
	}

}


void createTable(const char* name, char** columns, uint8_t* types, uint32_t numColumns){
		
	expandArray(database.tables, database.tableMem, Table);
	
	// Set table name
	currentTable.name = malloc(strlen(name) + 1);
	strcpy(currentTable.name, name);
	
	// Allocate memory for columns
	currentTable.columns = malloc(numColumns * sizeof(Column));
	
	currentTable.colMem.size = numColumns;
	currentTable.colMem.memory = 0;
	
	initColumns(numColumns, types);
	setNames(columns, numColumns);
	
	currentTable.fieldsMem.size = 0;
	currentTable.fieldsMem.memory = 0;

	// Update memory record for tableMem
	database.tableMem.size++; database.tableMem.memory--;

}

