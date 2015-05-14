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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* h1 = new ListNode(INT_MIN);
        h1->next = head;
        head = h1;
        
        ListNode* h2 = new ListNode(INT_MIN);
        ListNode* t2 = h2;
        
        while (head->next != NULL) {
            if (head->next->val < x)
                head = head->next;
            else {
                t2->next = head->next;
                head->next = head->next->next;
                
                t2 = t2->next;
                t2->next = NULL;
            }
        }
        
        head->next = h2->next;
        head = h1->next;
        
        delete h1;
        delete h2;
        
        return h1->next;
    }
};