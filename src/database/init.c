#include "../../include/PigSQL.h"


void createDb(const char* name){
  
 

  database.name = (char*)name;
  database.tables = NULL;
  database.tableMem.memory = 0;
  database.tableMem.size = 0;



}
