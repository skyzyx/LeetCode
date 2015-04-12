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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
            
        ListNode* walker = head->next;
        ListNode* runner = head->next->next;
        
        while (runner != NULL && walker != runner) {
            walker = walker->next;
            if (runner->next != NULL)
                runner = runner->next->next;
            else 
                runner = NULL;
        }
        
        if (runner == NULL)
            return NULL;
            
        runner = head;
        while (runner != walker) {
            runner = runner->next;
            walker = walker->next;
        }
        return runner;
    }
};