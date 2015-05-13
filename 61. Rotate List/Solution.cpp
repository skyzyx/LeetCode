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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k < 1)
            return head;
            
        int len = 1;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            len++;
        }
        
        p->next = head;
        
        int step = len - k % len;
        while (step > 0) {
            p = p->next;
            step--;
        }
        
        head = p->next;
        p->next = NULL;
        return head;
    }
};