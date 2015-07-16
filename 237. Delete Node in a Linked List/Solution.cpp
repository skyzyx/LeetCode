// LeetCode #237: Delete Node in a Linked List

/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};

/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
*/

/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        
        ListNode* prev = node;
        while (node->next != NULL) {
            int data = node->val;
            node->val = node->next->val;
            node->next->val = data;
            
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
        return;
    }
};
*/