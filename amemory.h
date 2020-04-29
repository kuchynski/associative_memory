//
// Associated memory with a string key
// kuchynskiandrei@gmail.com
// 2020
//

#ifndef H_AMEMORY
#define H_AMEMORY

#define MAX_CHARACTER   128

struct AMemory {
	char init;
	void *pointer[MAX_CHARACTER];
	char *alone_name;
	void *alone_pointer;
};

void AMemoryAddPointer(struct AMemory *a_memory, unsigned char *name, void *pointer);
void AMemoryRemovePointer(struct AMemory *a_memory, const unsigned char *name);
void AMemoryRemoveAll(struct AMemory *a_memory);
void* AMemoryGetPointer(struct AMemory *a_memory, const unsigned char *name);

#endif