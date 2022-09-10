#include "../include/PigSQL.h"
#include "../include/globals.h"
#include <stdio.h>

int main (void){

  createDb("Lol");

  printf("%s\n", databases[0].name);

  
  return 0;
}
