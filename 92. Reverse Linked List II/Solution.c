// LeetCode #92: Reverse Linked List II

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m >= n)
        return head;
        
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = INT_MIN;
    dummyHead->next = head;
    
    head = dummyHead;
    
    for (int i = 0; i < m-1; i++) // (m-1) node.
        head = head->next;
        
    struct ListNode* pre = head->next;
    struct ListNode* cur = pre->next;
    
    for (int i = 0; i < n-m; i++) {
        struct ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    
    head->next->next = cur;
    head->next = pre;
    
    head = dummyHead->next;
    free(dummyHead);
    return head;
}