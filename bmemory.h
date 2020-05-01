//
// Associated memory with a string key
// kuchynskiandrei@gmail.com
// 2020
//

#ifndef H_BMEMORY
#define H_BMEMORY

#define KEY_WIDTH			32
#define KEY_SYMBOL_WIDTH	4		// should be <= 16
#define KEY_SYMBOL_MASK		(0xFFFF >> (16-KEY_SYMBOL_WIDTH))
#define KEY_DEEPEST			(KEY_WIDTH / KEY_SYMBOL_WIDTH - ((KEY_WIDTH % KEY_SYMBOL_WIDTH)? 0 : 1))

struct BMemory {
	void *pointer[KEY_SYMBOL_MASK+1];
	unsigned alone_key;
	void *alone_pointer;
};

void BMemoryAddPointer(struct BMemory *b_memory, unsigned key, int deep, void *pointer);
void BMemoryRemovePointer(struct BMemory *b_memory, const unsigned key, int deep);
void BMemoryRemoveAll(struct BMemory *b_memory, int deep);
void* BMemoryGetPointer(struct BMemory *b_memory, const unsigned key, int deep);

#endif