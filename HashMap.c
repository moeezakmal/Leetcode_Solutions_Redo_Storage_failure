/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/


/*-------------------------------------------------------------------*/



// Array-based
// Time: O(1)
// Space: O(n)


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N pow(10, 6)

typedef struct {
    int *res;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    obj->res = (int*)malloc((N+1) * sizeof(int));
    for(size_t i=0; i<=N; i++)
    {
        obj->res[i] = -1;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->res[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->res[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->res[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->res);
    free(obj);
}


/*-------------------------------------------------------------------*/

// Linked List - based
// Time: O(1)
// Space: O(n)


#include <stdio.h>
#include <stdlib.h>

#define N 1000

typedef struct KeyValue KeyValue;

typedef struct {
    KeyValue *buckets[N];
} MyHashMap;

struct KeyValue {
    int key;
    int value;
    KeyValue *next;
};

MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    
    for(size_t i=0; i<N; i++)
        obj->buckets[i] = NULL;
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = key % N;
    KeyValue *bucket = obj->buckets[index];

    // check if key already exists
    while (bucket != NULL) {
        if (bucket->key == key) {
            bucket->value = value;
            return;
        }
        bucket = bucket->next;
    }
    
    
    KeyValue *newNode = (KeyValue*)malloc(sizeof(KeyValue));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
      
    if (obj->buckets[index] == NULL)
        obj->buckets[index] = newNode;
    
    else {
        KeyValue *current = obj->buckets[index];
        while(current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = key % N;
    KeyValue *bucket = obj->buckets[index];

    while (bucket != NULL) {
        if (bucket->key == key) 
            return bucket->value;
        bucket = bucket->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = key % N;
    KeyValue *bucket = obj->buckets[index];
    KeyValue *prev = NULL;

    while (bucket != NULL) {
        if (bucket->key == key) {
            
            if (prev != NULL) 
                prev->next = bucket->next;
            else
                obj->buckets[index] = bucket->next;
            
            free(bucket);
            return;
        }
        prev = bucket;
        bucket = bucket->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(size_t i=0; i<N; i++) {
        KeyValue *bucket = obj->buckets[i];
        while(bucket != NULL) {
            KeyValue *temp = bucket;
            bucket = bucket->next;
            free(temp);
        }
    }
    free(obj);
}