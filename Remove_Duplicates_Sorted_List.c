// Time: O(n) -> traversed once
// Space: O(1)


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val)
        {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
            curr = curr->next;
    }
    return head;
}