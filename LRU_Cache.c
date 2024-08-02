#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
};


typedef struct {
    int capacity;
    int size; // current size of LRUCache
    Node *head; //Dummy Head of Doubly Linkedlist
    Node *tail; //Dummy Tail of Doubly Linkedlist
    Node **hashmap;
} LRUCache;


Node* nodeCreate(int key, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev =  NULL;
    node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = nodeCreate(0,0);
    obj->tail = nodeCreate(0,0);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    /*  obj->hashmap = (Node**)malloc(capacity * sizeof(Node*));
        for(size_t i=0; i<capacity; i++) {
            obj->hashmap[i] = NULL;
        } // using malloc               */   
    // obj->hashmap = (Node**)calloc(capacity, sizeof(Node*));
    obj->hashmap = (Node**)calloc(10001, sizeof(Node*));
    return obj;
}

void nodeRemove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void nodeInsert(LRUCache* obj, Node* node) {
    node->next = obj->tail;
    node->prev = obj->tail->prev;
    obj->tail->prev->next = node;
    obj->tail->prev = node;
}

// unsigned int hash(int capacity, int key) {
//     return key % capacity;
// }

int lRUCacheGet(LRUCache* obj, int key) {
    // unsigned int index = hash(obj->capacity, key);
    Node *node = obj->hashmap[key]; //could be NULL
    if (node) {
        //making it MRU
        nodeRemove(node);
        nodeInsert(obj, node);

        return node->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *node = obj->hashmap[key];
    if (node) { // if already exists
        nodeRemove(node);
        node->value = value;
    }
    else { // if doesn't exist
        if (obj->size == obj->capacity) { // if capacity full
            Node *lruNode = obj->head->next;
            nodeRemove(lruNode);
            obj->hashmap[lruNode->key] = NULL;
            free(lruNode);
            obj->size--;
        }
        node = nodeCreate(key, value);
        obj->hashmap[key] = node;
        obj->size++;
    }
    nodeInsert(obj, node);

}

void lRUCacheFree(LRUCache* obj) {
    Node* current = obj->head;
    while (current) { // free doubly linked-list
        Node *x = current->next;
        free(current);
        current = x;
    }
    free(obj->hashmap); // free hashmap coz they were only pointers
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/