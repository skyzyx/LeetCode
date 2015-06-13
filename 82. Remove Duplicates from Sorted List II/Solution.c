// LeetCode #82: Remove Duplicates from Sorted List II

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

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