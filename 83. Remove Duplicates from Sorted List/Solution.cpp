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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* p = head;
        while (p->next != NULL) {
            if (p->val == p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};

 
/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        while (cur != NULL) {
            if (pre->val != cur->val)
                pre = cur;
            else
                pre->next = cur->next;
                
            cur = cur->next;
        }
        return head;
    }
};
*/