/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// http://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return NULL;
        
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = -1;
    dummyHead->next = head;
    
    struct ListNode* helper = dummyHead;
    
    while (helper->next != NULL) {
        if (helper->next->val == val) {
            struct ListNode* tempNode = helper->next;
            helper->next = tempNode->next;
        } else {
            helper = helper->next;
        }
    }
    
    return dummyHead->next;
}