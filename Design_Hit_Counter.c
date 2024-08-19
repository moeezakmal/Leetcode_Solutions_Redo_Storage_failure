// Time: O(1) for all other operations, O(n) for getHits but amortized to O(1)
// Space: O(n)


#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 1000

typedef struct {
    int* hits;
    int size;
    int capacity;
    int front;
    int back;
} HitCounter;


HitCounter* hitCounterCreate() {
    HitCounter* obj = (HitCounter*)malloc(sizeof(HitCounter));
    obj->hits = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    obj->size = 0;
    obj->capacity = INITIAL_CAPACITY;
    obj->front = 0;
    obj->back = 0;
    return obj;
}

void hitCounterHit(HitCounter* obj, int timestamp) {
    if (obj->size == obj->capacity) {
        // Resize the queue (dynamic array)
        obj->capacity *= 2;
        obj->hits = (int*)realloc(obj->hits, obj->capacity * sizeof(int));
    }
    obj->hits[obj->back] = timestamp;
    obj->back = (obj->back + 1) % obj->capacity;
    obj->size++;
}

int hitCounterGetHits(HitCounter* obj, int timestamp) {
    while (obj->size > 0) {
        int diff = timestamp - obj->hits[obj->front];
        if (diff >= 300) {
            // Remove the hit that is older than 5 minutes
            obj->front = (obj->front + 1) % obj->capacity;
            obj->size--;
        } else {
            break;
        }
    }
    return obj->size;
}

void hitCounterFree(HitCounter* obj) {
    free(obj->hits);
    free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/