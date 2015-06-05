// LeetCode #160: Intersection of Two Linked Lists

/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

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