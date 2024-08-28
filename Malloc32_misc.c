void *malloc32() {
    void *mem = malloc(32+31+sizeof(void*));
    void **ptr = (void**)((uintptr_t)(mem+31+sizeof(void*)) & ~(0x1F));
    ptr[-1] = mem;
    printf("malloc %x %x %x \n", mem, ptr, ptr[-1]);
    return ptr;
}

void free32(void *ptr) {
    printf("free %x\n", ((void **)ptr)[-1]);
    free(((void **)ptr)[-1]);
}

int main(void) {
    puts("Hello World!");
    void * x = malloc32();    
    printf("%x %x\n", x, ((void **)x)[-1]);
    free32(x);
    return 0;
}


// 34 byte alignment

#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(size_t size, size_t alignment) {
    // Allocate extra memory: original allocation + alignment padding + space to store original pointer
    void* original_ptr = malloc(size + alignment - 1 + sizeof(void*));
    if (original_ptr == NULL) {
        return NULL;  // Allocation failed
    }

    // Add alignment - 1 to the pointer, then round down to the nearest multiple of alignment
    uintptr_t aligned_ptr = (uintptr_t)original_ptr + sizeof(void*) + (alignment - 1);
    aligned_ptr = (aligned_ptr / alignment) * alignment;

    // Store the original pointer just before the aligned memory
    ((void**)aligned_ptr)[-1] = original_ptr;

    return (void*)aligned_ptr;
}

void aligned_free(void* ptr) {
    if (ptr != NULL) {
        // Retrieve the original pointer and free it
        free(((void**)ptr)[-1]);
    }
}

int main() {
    size_t alignment = 34;  // Alignment requirement: 34 bytes
    size_t size = 100;      // Example allocation size

    // Allocate aligned memory
    void* ptr = aligned_malloc(size, alignment);
    if (ptr != NULL) {
        // Use the allocated memory...
        
        // Free the aligned memory
        aligned_free(ptr);
    }

    return 0;
}
