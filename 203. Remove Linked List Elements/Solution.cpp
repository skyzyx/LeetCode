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