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
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        
        ListNode* p = dummyHead;
        while (p->next != NULL) {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dummyHead->next;
    }
};