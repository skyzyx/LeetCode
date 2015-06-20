// LeetCode #24: Swap Nodes in Pairs

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        
        while (cur != NULL && cur->next != NULL) {
            ListNode* tmp = cur->next->next;
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = tmp;
            
            pre = cur;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};