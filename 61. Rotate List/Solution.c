/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k < 1)
        return head;
        
    int len = 1;
    struct ListNode* p = head;
    while (p->next) {
        p = p->next;
        len++;
    }
    
    p->next = head;
    
    int step = len - k % len;
    while (step > 0) {
        p = p->next;
        step--;
    }
    
    head = p->next;
    p->next = NULL;
    
    return head;
}