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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n == 0)
            return head;
            
        ListNode* runner = head;
        ListNode* walker = head;
        
        for (int i = 0; i < n; i++)
            if (runner != NULL)
                runner = runner->next;
                
        if (runner == NULL)
            return head->next;
            
        while (runner->next != NULL) {
            runner = runner->next;
            walker = walker->next;
        }
        
        walker->next = walker->next->next;
        return head;
    }
};