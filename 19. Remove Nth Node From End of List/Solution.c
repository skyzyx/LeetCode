// LeetCode #19: Remove Nth Node From End of List

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n == 0)
        return head;
            
    struct ListNode* runner = head;
    struct ListNode* walker = head;
        
    for (int i = 0; i < n; i++)
        if (runner != NULL)
            runner = runner->next;
            
    if (runner == NULL)
        return head->next;
    
    while (runner->next != NULL) {
        runner = runner->next;
        walker = walker->next;
    }
        
    walker->next = walker->next->next;
    return head;
}