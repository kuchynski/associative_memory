//
// Associated memory with a string key
// kuchynskiandrei@gmail.com
// 2020
//

#include <string.h>
#include <stdio.h>

#include "amemory.h"
#include "bmemory.h"

#define CAPACITY        10

int main(int argc, char** argv)
{
    struct AMemory a_memory;
    struct BMemory b_memory;
    int values[CAPACITY];
    int *values_pointer = values;

            // Init
    printf("Start here\n");
    memset(&a_memory, 0, sizeof(struct AMemory));
    memset(&b_memory, 0, sizeof(struct BMemory));

    for(int i = 0; i < CAPACITY; i++)
        values[i] = i;

    AMemoryAddPointer(&a_memory, "Number one", values_pointer++);
    AMemoryAddPointer(&a_memory, "The second one", values_pointer++);
    AMemoryAddPointer(&a_memory, "The same", values_pointer++);
    AMemoryAddPointer(&a_memory, "Just a third", values_pointer++);

    if(AMemoryGetPointer(&a_memory, "The second one")) {
        printf("\"The second one\" is holded\n");
    }

    if(AMemoryGetPointer(&a_memory, "The second o ne") == NULL) {
        printf("\"The second o ne\" is not\n");
    }

    AMemoryRemovePointer(&a_memory, "The second one");

    if(AMemoryGetPointer(&a_memory, "The second one") == NULL) {
        printf("\"The secondo ne\" is not longer more\n");
    }

    AMemoryRemoveAll(&a_memory);

    printf("---------------------------------------------------------------------------\n");

    BMemoryAddPointer(&b_memory, 0x11223344, 0, values_pointer++);
    BMemoryAddPointer(&b_memory, 0x11223345, 0, values_pointer++);
    BMemoryAddPointer(&b_memory, 0x11223246, 0, values_pointer++);
    BMemoryAddPointer(&b_memory, 0x11223247, 0, values_pointer++);

    if(BMemoryGetPointer(&b_memory, 0x11223344, 0)) {
        printf("0x11223344 is holded\n");
    }

    if(BMemoryGetPointer(&b_memory, 0x11223346, 0) == NULL) {
        printf("0x11223346 is not\n");
    }

    BMemoryRemovePointer(&b_memory, 0x11223344, 0);

    if(BMemoryGetPointer(&b_memory, 0x11223344, 0) == NULL) {
        printf("0x11223344 is not longer more\n");
    }

    BMemoryRemoveAll(&b_memory, 0);

    return 0;
}
