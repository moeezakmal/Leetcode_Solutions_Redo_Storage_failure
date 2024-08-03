/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

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
    int index = (key % N + N) % N;
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
    int index = (key % N + N) % N;
    KeyValue *bucket = obj->buckets[index];

    while (bucket != NULL) {
        if (bucket->key == key) 
            return bucket->value;
        bucket = bucket->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = (key % N + N) % N;
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



int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    MyHashMap* map = myHashMapCreate();

    for(int i = 0; i < numsSize; i++) {
        if(myHashMapGet(map, target - nums[i]) != -1) {
            *returnSize = 2;
            int* result = (int*)malloc(*returnSize * sizeof(int));
            result[0] = myHashMapGet(map, target - nums[i]);
            result[1] = i;
            myHashMapFree(map);
            return result;
        }
        myHashMapPut(map, nums[i], i);
    }
    *returnSize = 0;
    myHashMapFree(map);
    return NULL;
}