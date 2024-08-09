// Time: O(nlogk) -> where k is depth of merging, n is merging of 2 lists
// Space: O(1)

struct ListNode* merge2Lists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* point = head;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            point->next = l1;
            l1 = l1->next;
        } else {
            point->next = l2;
            l2 = l1;
            l1 = point->next->next;
        }
        point = point->next;
    }
    if (!l1) {
        point->next = l2;
    } else {
        point->next = l1;
    }
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int interval = 1;
    while (interval < listsSize) {
        for (int i = 0; i < listsSize - interval; i += interval * 2)
            lists[i] = merge2Lists(lists[i], lists[i + interval]);
        interval *= 2;
    }
    return listsSize > 0 ? lists[0] : NULL;
}