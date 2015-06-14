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
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m >= n)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        
        head = dummyHead;
        
        for (int i = 0; i < m-1; i++)
            head = head->next;
            
        ListNode* pre = head->next;
        ListNode* cur = head->next->next;
        
        for (int i = 0; i < n-m; i++) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        head->next->next = cur;
        head->next = pre;
        
        head = dummyHead->next;
        delete(dummyHead);
        return head;
    }
};