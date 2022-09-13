#include "../../include/PigSQL.h"
#include <stdlib.h>


void** stack;
Memory stackMem;

void** sp;
void** bp;


void initStack(){
	
	stack = malloc(10 * sizeof(void*));
	stackMem.size = 0; stackMem.memory = 10;

	bp = stack;
	sp = stack;

}


void push(void* item){
	
	expandArray(stack, stackMem, void*);

	*sp = item;
	sp++;

	stackMem.size++; stackMem.memory--;
}


void* pop(){
	
	if(sp == bp) return NULL;

	sp--;
	stackMem.size--; stackMem.memory++;

	return  *sp;
}


void destroyStack(){

	free(stack);
	stack = NULL;
	stackMem.size = 0; stackMem.memory = 0;

	sp = NULL;
	bp = NULL;
}


size_t stackSize(){
	
	return stackMem.size;
}
