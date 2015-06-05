// LeetCode #143: Reorder List

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
            
        ListNode* runner = head;
        ListNode* walker = head;
        while (runner->next != NULL && runner->next->next != NULL) {
            runner = runner->next->next;
            walker = walker->next;
        }
        
        ListNode* rightHalf = reverseList(walker->next);
        walker->next = NULL;
        
        while (rightHalf != NULL) {
            ListNode* tmp = rightHalf;
            rightHalf = rightHalf->next;
            
            tmp->next = head->next;
            head->next = tmp;
            head = head->next->next;
        }
        
        return;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};