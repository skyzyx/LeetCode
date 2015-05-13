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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m >= n)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        
        head = dummyHead;
        
        for (int i = 0; i < m-1; i++)
            head = head->next;
            
        ListNode* pre = head->next;
        ListNode* cur = head->next->next;
        
        for (int i = 0; i < n-m; i++) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        head->next->next = cur;
        head->next = pre;
        
        head = dummyHead->next;
        delete(dummyHead);
        return head;
    }
};