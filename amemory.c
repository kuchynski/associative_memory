//
// Associated memory with a string key
// kuchynskiandrei@gmail.com
// 2020
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "amemory.h"


void AMemoryAddPointer(struct AMemory *a_memory, unsigned char *name, void *pointer)
{
	const unsigned char symbol = *name;

	if(symbol) {
		void *next = a_memory->pointer[symbol];
		if(a_memory->init == 0) {
			a_memory->alone_pointer = pointer;
			a_memory->alone_name = name;
			a_memory->init = 1;
		}
		else {
			if(next == NULL) {
				next = malloc(sizeof(struct AMemory));
				if(next == NULL)
					return;
				memset(next, 0, sizeof(struct AMemory));
				a_memory->pointer[symbol] = next;
			}
			if(a_memory->alone_pointer) {
				char *name_tmp = a_memory->alone_name;
				void *pointer_tmp = a_memory->alone_pointer;
				a_memory->alone_name = NULL;
				a_memory->alone_pointer = NULL;
				AMemoryAddPointer(a_memory, name_tmp, pointer_tmp);
			}
			AMemoryAddPointer((struct AMemory*)next, name + 1, pointer);
		}
	}
	else {
		//if(a_memory->pointer[0] == NULL)
		a_memory->pointer[0] = pointer;	// set successfully
	}
}

void AMemoryRemovePointer(struct AMemory *a_memory, const unsigned char *name)
{
	const unsigned char symbol = *name;

	if(symbol) {
		void *next = a_memory->pointer[symbol];
		a_memory->alone_pointer = NULL;
		a_memory->alone_name = NULL;
		if(next)
			AMemoryRemovePointer((struct AMemory*)next, name + 1);
	}
	else {
		a_memory->pointer[0] = NULL;
	}
}

void AMemoryRemoveAll(struct AMemory *a_memory)
{
	unsigned symbol;

	for(symbol = 1; symbol < MAX_CHARACTER; symbol++) {
		void *next = a_memory->pointer[symbol];
		if(next) {
			AMemoryRemoveAll((struct AMemory*)next);
			free(next);
			a_memory->pointer[symbol] = NULL;
		}
	}
	memset(a_memory, 0, sizeof(struct AMemory));
}

void* AMemoryGetPointer(struct AMemory *a_memory, const unsigned char *name)
{
	const unsigned char symbol = *name;
	void *ptr = a_memory->pointer[symbol];

	if(symbol) {
		if(a_memory->alone_pointer)
			ptr = strcmp(a_memory->alone_name, name)? NULL : a_memory->alone_pointer;
		else if(ptr)
			ptr = AMemoryGetPointer((struct AMemory*)ptr, name + 1);
	}

	return ptr;
}
