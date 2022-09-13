#include "../include/PigSQL.h"
#include "../include/globals.h"
#include <stdio.h>

int main(void){

  createDb("Lol");
	
	initStack();

	push("Wasssuuuuupppppp");

	printf("%s\n", (char*)pop());

  return 0;
}
