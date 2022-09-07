#include "../../include/PigSQL.h"
#include <string.h>


void splitStr(const char* str, char** dest){
  
  Size s = {.size = 0, .memory = 0};
  
  append(dest, str, s, char*);

}

