// LeetCode #203: Remove Linked List Elements

/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

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