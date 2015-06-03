// LeetCode #141: Linked List Cycle

/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
        
    struct ListNode* runner = head;
    struct ListNode* walker = head;
    
    while (runner != NULL && runner->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
        if (runner == walker)
            return true;
    }
    return false;
}