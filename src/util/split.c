#include "../../include/PigSQL.h"
#include <string.h>
#include <stdio.h>

char** splitStr(char* str, char sep, size_t* numWords){
  
	char** dest = NULL;
  Memory destMem = {.size = 0, .memory = 0};
  
  char* buf = NULL;
  Memory bufMem = {.size = 0, .memory = 0};
  
  char* temp = str;

  while(*temp){
	
		if(*temp != sep){
			
			expandArray(buf, bufMem, char);
			buf[bufMem.size] = *temp;
			bufMem.size++; bufMem.memory--;
		}

		else if(*temp == sep &&  *(temp + 1) != sep){
			
			expandArray(buf, bufMem, char);
			buf[bufMem.size] = 0;

			expandArray(dest, destMem, char*);
			dest[destMem.size] = buf;
			destMem.size++; destMem.memory--;

			buf = NULL;
			bufMem.size = 0; bufMem.memory = 0;
		}

    temp++;
  }
	
	// Append the last word
	expandArray(buf, bufMem,  char);
	buf[bufMem.size] = 0;

	expandArray(dest, destMem, char*);
	dest[destMem.size] = buf;
	
	// Store the size of 'dest' in 'numWords'
	destMem.size++;
	*numWords = destMem.size;

	return dest;
} 

