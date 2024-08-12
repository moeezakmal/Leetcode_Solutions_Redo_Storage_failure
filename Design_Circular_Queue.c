// Time: O(1)
// Space: O(n)


#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int *queue;
    int headIndex;
    int count;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    
    obj->queue = (int*)malloc(sizeof(int) * k);
    
    obj->capacity = k;
    obj->headIndex = 0;
    obj->count = 0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->count == obj->capacity) return false;
    obj->queue[(obj->headIndex + obj->count) % obj->capacity] = value;
    obj->count += 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->count == 0) return false;
    obj->headIndex = (obj->headIndex + 1) % obj->capacity;
    obj->count -= 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->count == 0) return -1;
    return obj->queue[obj->headIndex];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->count == 0) return -1;
    int tailIndex = (obj->headIndex + obj->count - 1) % obj->capacity;
    return obj->queue[tailIndex];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->count == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->count == obj->capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/