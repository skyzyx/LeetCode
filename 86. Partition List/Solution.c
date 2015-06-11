// LeetCode #86: Partition List

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL || head->next == NULL)
        return head;
        
    struct ListNode* h1 = malloc(sizeof(struct ListNode));
    h1->val = 0;
    h1->next = head;
    head = h1;
    
    struct ListNode* h2 = malloc(sizeof(struct ListNode));
    h2->val = 0;
    h2->next = NULL;
    struct ListNode* t2 = h2;
    
    while (head->next != NULL) {
        if (head->next->val < x)
            head = head->next;
        else {
            t2->next = head->next;
            head->next = head->next->next;
            t2 = t2->next;
            t2->next = NULL;
        }
    }
    
    head->next = h2->next;
    head = h1->next;
    free(h1);
    free(h2);
    return head;
}