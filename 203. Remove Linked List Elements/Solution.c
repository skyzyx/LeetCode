/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return head;
        
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    dummyHead->val = INT_MIN;
    
    struct ListNode* p = dummyHead;
    while (p->next != NULL) {
        if (p->next->val == val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return dummyHead->next;
}