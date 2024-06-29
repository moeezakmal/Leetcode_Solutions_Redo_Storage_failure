class Solution {
public:
    
    // Time: O(n)
    // Space: O(1)
    
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};