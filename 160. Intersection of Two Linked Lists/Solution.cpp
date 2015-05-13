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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
    
private:
    int getLength(ListNode* head) {
        if (head == NULL)
            return 0;
            
        int res = 0;
        while (head) {
            head = head->next;
            res++;
        }
        return res;
    }
};