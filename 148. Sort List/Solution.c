/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = INT_MIN;
    dummyHead->next = l1;
        
    struct ListNode* pre = dummyHead;
        
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val)
            l1 = l1->next;
        else {
            struct ListNode* next = l2->next;
            pre->next = l2;
            l2->next = l1;
                
            l2 = next;
        } 
            
        pre = pre->next;
    }
        
    if (l2 != NULL)
        pre->next = l2;
            
    return dummyHead->next;
}

struct ListNode* mergeSort(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
            
    struct ListNode* walker = head;
    struct ListNode* runner = head;
    while (runner->next != NULL && runner->next->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
    }
    
    struct ListNode* head2 = walker->next;
    walker->next = NULL;
        
    struct ListNode* head1 = head;
        
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    return mergeSort(head);
}