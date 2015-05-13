/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
        
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = -1;
    dummyHead->next = NULL;
    
    struct ListNode* p = dummyHead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val >= l2->val) {
            p->next = l2;
            l2 = l2->next;
        } else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    
    if (l1 != NULL)
        p->next = l1;
    if (l2 != NULL)
        p->next = l2;
        
    return dummyHead->next;
}