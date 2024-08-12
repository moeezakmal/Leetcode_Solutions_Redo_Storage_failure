// Time: O(n)
// Space: O(1)

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct {
    int *array;
    int size;
} Allocator;


Allocator* allocatorCreate(int n) {
    Allocator *obj = (Allocator *)malloc(sizeof(Allocator));

    obj->array = (int *)malloc(n * sizeof(int));

    obj->size = n;
    memset(obj->array, -1, n * sizeof(int)); // Initialize array to -1

    return obj;
}

int allocatorAllocate(Allocator* obj, int size, int mID) {
    if (size > obj->size) return -1;

    int count = 0;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < obj->size; i++) {
        if (obj->array[i] == -1) {
            count++;
        } else {
            count = 0;
            startIndex = i + 1;
        }

        if (count == size) {
            endIndex = i;
            break;
        }
    }

    if (count < size) return -1; // Not enough contiguous space

    for (int i = startIndex; i <= endIndex; i++) {
        obj->array[i] = mID;
    }

    return startIndex;
}

int allocatorFree(Allocator* obj, ...) {
    va_list argp;
    va_start(argp, obj);
    int mID = va_arg(argp, int);
    
    int count = 0;

    for (int i = 0; i < obj->size; i++) {
        if (obj->array[i] == mID) {
            obj->array[i] = -1;
            count++;
        }
    }

    return count;
}

// void allocatorFree(Allocator* obj) {
//     free(obj->array);
//     free(obj);
// }

/**
 * Your Allocator struct will be instantiated and called as such:
 * Allocator* obj = allocatorCreate(n);
 * int param_1 = allocatorAllocate(obj, size, mID);
 
 * int param_2 = allocatorFree(obj, mID);
 
 * allocatorFree(obj);
*/