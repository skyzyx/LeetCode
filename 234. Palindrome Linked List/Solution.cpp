// LeetCode #234: Palindrome Linked List

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        stack<ListNode*> s;
        ListNode* p = head;
        
        while (p != NULL) {
            s.push(p);
            p = p->next;
        }
        
        while (!s.empty()) {
            ListNode* curr = s.top();
            s.pop();
            if (curr->val != head->val)
                return false;
            head = head->next;
        }
        return true;
    }
};