// LeetCode #61: Rotate List

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

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