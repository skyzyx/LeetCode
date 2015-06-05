// LeetCode #147: Insertion Sort List

// Sort a linked list using insertion sort.

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* dummyHead = new ListNode(INT_MIN);
        //dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        
        while (cur != NULL) {
            pre = dummyHead;
            ListNode* next = cur->next;
            while (pre->next != NULL && pre->next->val <= cur->val)
                pre = pre->next;
            
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummyHead->next;
    }
};

 
/* 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* cur = head->next;
        while (cur != NULL) {
            ListNode* tmp = head;
            while (tmp != cur) {
                if (tmp->val > cur->val) {
                    int data = cur->val;
                    cur->val = tmp->val;
                    tmp->val = data;
                }
                tmp = tmp->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
*/