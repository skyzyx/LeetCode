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