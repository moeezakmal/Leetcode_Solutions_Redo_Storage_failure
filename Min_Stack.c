// Time of Operations: O(1)
// Space: O(n)

/*more robustness and functionalities to be added later e.g if pop() called on empty stack*/

#include <stdlib.h>
#include <stdio.h>


#define CAP 30000

typedef struct {
    int val;
    int min_val;
} data_t;

typedef struct {
    data_t *buffer;
    int capacity;
    int size;
} MinStack;


#define min(a, b) ({ \
    __typeof__(a) _a = a; \
    __typeof__(b) _b = b; \
    (_a < _b) ? _a : _b; \
})

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    
    obj->capacity = CAP;
    obj->size = 0;
    obj->buffer = (data_t*)malloc(sizeof(data_t) * obj->capacity);

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    const int idx = obj->size;
    obj->buffer[idx].val = val;
    if (idx == 0)
        obj->buffer[idx].min_val = val;
    else
        obj->buffer[idx].min_val = min(val, obj->buffer[idx-1].min_val);
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->buffer[obj->size-1].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->buffer[obj->size-1].min_val;
}

void minStackFree(MinStack* obj) {
    free(obj->buffer);
    obj->buffer = NULL;
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/