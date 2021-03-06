// LeetCode #2: Add Two Numbers

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
        
    struct ListNode* res = malloc(sizeof(struct ListNode*));
    res->val = -1;
    res->next = NULL;
    
    struct ListNode* dummyHead = res;
    
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            carry += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            carry += l2->val;
            l2 = l2->next;
        }
        
        struct ListNode* tmp = malloc(sizeof(struct ListNode*));
        tmp->val = carry % 10;
        tmp->next = NULL;
        
        res->next = tmp;
        res = res->next;
        
        carry /= 10;
    }
    
    if (carry == 1) {
        struct ListNode* ans = malloc(sizeof(struct ListNode*));
        ans->val = 1;
        ans->next = NULL;
        
        res->next = ans;
    }
    
    return dummyHead->next;
        
}