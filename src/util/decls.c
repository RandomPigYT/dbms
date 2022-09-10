#include "../../include/PigSQL.h"
#include "../../include/structs.h"
#include "../../include/util.h"
#include "../../include/globals.h"


Database* databases;
Memory DbMem = {.memory = 0, .size = 0};
