// Time: O(1) -> head, O(k) -> index, O(N) -> tail
// Space: O(1) -> for all operations 


// Definition for singly-linked list.
typedef struct {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct {
    int size;
    ListNode* head;  // pseudo-head
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->size = 0;
    obj->head = (ListNode*)malloc(sizeof(ListNode));
    obj->head->val = 0;  // This value is not used, as the head is a sentinel
    obj->head->next = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    ListNode* curr = obj->head;
    // Move to the (index + 1)-th node because of dummy head
    for (int i = 0; i < index + 1; i++) {
        curr = curr->next;
    }
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index < 0) index = 0;

    obj->size++;
    ListNode* pred = obj->head;
    for (int i = 0; i < index; i++) {
        pred = pred->next;
    }

    ListNode* toAdd = (ListNode*)malloc(sizeof(ListNode));
    toAdd->val = val;
    toAdd->next = pred->next;
    pred->next = toAdd;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    obj->size--;
    ListNode* pred = obj->head;
    for (int i = 0; i < index; i++) {
        pred = pred->next;
    }

    ListNode* toDelete = pred->next;
    pred->next = toDelete->next;
    free(toDelete);
}

void myLinkedListFree(MyLinkedList* obj) {
    ListNode* curr = obj->head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
 */
