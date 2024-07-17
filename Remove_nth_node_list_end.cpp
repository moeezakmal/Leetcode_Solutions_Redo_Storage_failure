// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_root = new ListNode(0, head);

        ListNode* l = dummy_root;
        ListNode* r = head;
        
        while (n>0 && r!=NULL){
            r = r->next;
            n--;
        }

        while (r!=NULL)
        {
            l=l->next;
            r=r->next;
        }

        l->next = l->next->next;

        return dummy_root->next;
    }
};