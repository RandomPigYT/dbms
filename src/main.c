#include "../include/PigSQL.h"
#include "../include/globals.h"
#include <stdio.h>

int main(void){

  createDb("Lol");
	
	char* c[3] = {"Hello", "hi", "how"};
	uint8_t T[3] = {INT, VAR_CHAR, TEXT};
	
	createTable("hello", c, T, 3);
	createTable("hello", c, T, 3);


  return 0;
}
