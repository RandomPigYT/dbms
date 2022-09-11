#include "../../include/PigSQL.h"


Database* databases;
Memory DbMem = {.memory = 0, .size = 0};

uint64_t currentDb;
