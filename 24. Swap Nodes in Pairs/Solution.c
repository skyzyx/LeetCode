/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
        
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = INT_MIN;
    dummyHead->next = head;
    
    struct ListNode* pre = dummyHead;
    struct ListNode* cur = head;
    
    while (cur != NULL && cur->next != NULL) {
        struct ListNode* tmp = cur->next->next;
        cur->next->next = cur;
        pre->next = cur->next;
        cur->next = tmp;
        
        pre = cur;
        cur = cur->next;
    }
    return dummyHead->next;
}