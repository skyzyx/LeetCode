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
            return NULL;
            
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* helper = dummyHead;
        while (helper->next != NULL) {
            if (helper->next->val == val) {
                ListNode* tempNode = helper->next;
                helper->next = tempNode->next;
            } else {
                helper = helper->next;
            }
        }
        
        return dummyHead->next;
    }
};