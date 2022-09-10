#include "../../include/PigSQL.h"
#include "../../include/structs.h"
#include "../../include/util.h"
#include "../../include/globals.h"


void createDb(const char* name){
  
  Database db;

  db.name = (char*)name;
  db.tables = NULL;
  db.tableMem.memory = 0;
  db.tableMem.size = 0;

  expandArray(databases, DbMem, Database);

  databases[DbMem.size] = db;
  DbMem.size++;
  DbMem.memory--;

}
