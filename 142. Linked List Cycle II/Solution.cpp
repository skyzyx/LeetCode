// LeetCode #142: Linked List Cycle II

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

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
            
        ListNode* walker = head;
        ListNode* runner = head;
        bool hasCircle = false;
        
        while (runner != NULL && runner->next != NULL) {
            runner = runner->next->next;
            walker = walker->next;
            if (runner == walker) {
                hasCircle = true;
                break;
            }
        }
        
        if (hasCircle == true) {
            runner = head;
            while (runner != walker) {
                runner = runner->next;
                walker = walker->next;
            }
            return runner;
        }
        
        return NULL;
    }
};