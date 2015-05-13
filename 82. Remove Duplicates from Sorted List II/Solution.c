/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = INT_MIN;
    dummyHead->next = head;
    
    struct ListNode* pre = dummyHead;
    struct ListNode* cur = head;
    
    while (cur != NULL) {
        while (cur->next != NULL && pre->next->val == cur->next->val)
            cur = cur->next;
            
        if (pre->next == cur)
            pre = pre->next;
        else
            pre->next = cur->next;
            
        cur = cur->next;
    }
    return dummyHead->next;
}