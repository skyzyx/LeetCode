// LeetCode #2: Add Two Numbers

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
            
        ListNode* res = new ListNode(-1); 
        ListNode* dummyHead = res;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            res->next = new ListNode(carry % 10);
            res = res->next;
            carry /= 10;
        }
        
        if (carry == 1)
            res->next = new ListNode(carry);
            
        return dummyHead->next;
    }
};