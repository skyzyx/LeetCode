// LeetCode #206: Reverse Linked List

/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) { // Recursion
    if (head == NULL || head->next == NULL)
        return head;
        
    struct ListNode* rest = head->next;
    head->next = NULL;
    
    struct ListNode* reverseRest = reverseList(rest);
    rest->next = head;
    
    return reverseRest;
}

/*
struct ListNode* reverseList(struct ListNode* head) { // Iteration
    if (head == NULL || head->next == NULL)
        return head;
        
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
*/