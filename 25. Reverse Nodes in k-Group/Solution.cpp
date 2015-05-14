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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k < 2)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        
        ListNode* prev = dummyHead;
        
        int count = 0;
        while (head != NULL) {
            count++;
            if (count == k) {
                prev = reverse(prev, head->next);
                head = prev->next;
                count = 0;
            } else {
                head = head->next;
            }
        }
        return dummyHead->next;
    }
    
private:
    ListNode* reverse(ListNode* prev, ListNode* next) {
        ListNode* last = prev->next;
        ListNode* curr = prev->next->next;
        
        while (curr != next) {
            last->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            
            curr = last->next;
        }
        return last;
    }
};