#include "../include/PigSQL.h"
#include "../include/globals.h"
#include <stdio.h>

int main(void){

  createDb("Lol");
	
	size_t size = 0;

	char** w = splitStr("Hello mate, how the hell are you doing?", ' ', &size);
	
	for(size_t i = 0; i < size; i++){
		printf("%s\n", w[i]);
	}
  
	freeSplitStr(w, size);
	

  return 0;
}
