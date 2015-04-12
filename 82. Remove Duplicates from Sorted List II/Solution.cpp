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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        
        while (cur != NULL) {
            while (cur->next != NULL && pre->next->val == cur->next->val)
                cur = cur->next;
                
            if (pre->next == cur)
                pre = pre->next;
            else
                pre->next = cur->next;
                
            cur = cur->next;
        }
        return dummyHead->next;
    }
};