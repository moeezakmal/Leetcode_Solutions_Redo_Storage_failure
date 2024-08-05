// Time: O(n) -> where n is greater of l1 and l2 length
// Space: O(n)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int _val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = _val;
    node->next = NULL;
    return node;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int car = 0;
    struct ListNode* l3 = newNode(0);
    struct ListNode* res = l3;

    int sum = 0;

    while(l1 != NULL || l2 != NULL)
    {   
        if (l1 == NULL) sum = l2->val + car;
        else if (l2 == NULL) sum = l1->val + car;
        else sum = l1->val + l2->val + car;
           
        car = sum/10;
        sum = sum % 10;
        l3->next = newNode(sum);
        l3 = l3->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (car == 1)
        l3->next = newNode(1);

    return res->next;
}