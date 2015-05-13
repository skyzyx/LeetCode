/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLength(struct ListNode* head) {
    if (head == NULL)
        return 0;
        
    int res = 0;
    while (head) {
        head = head->next;
        res++;
    }
    return res;
} 
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int alen = getLength(headA);
    int blen = getLength(headB);
    
    while (alen > blen) {
        headA = headA->next;
        alen--;
    }
    
    while (blen > alen) {
        headB = headB->next;
        blen--;
    }
    
    while (headA != NULL && headB != NULL) {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}