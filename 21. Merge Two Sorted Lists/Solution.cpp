// LeetCode #21: Merge Two Sorted Lists

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = l1;
        
        ListNode* pre = dummyHead;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val)
                l1 = l1->next;
            else {
                ListNode* l2next = l2->next;
                pre->next = l2;
                l2->next = l1;
                
                l2 = l2next;
            }
            
            pre = pre->next;
        }
        
        if (l2 != NULL)
            pre->next = l2;
            
        return dummyHead->next;
    }
};