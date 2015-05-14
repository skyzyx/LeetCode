/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* prev, struct ListNode* next) {
    struct ListNode* last = prev->next;
    struct ListNode* curr = prev->next->next;
    
    while (curr != next) {
        last->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        
        curr = last->next;
    }
    return last;
} 

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k < 2)
        return head;
        
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = INT_MIN;
    dummyHead->next = head;
    
    struct ListNode* prev = dummyHead;
    int count = 0;
    
    while (head != NULL) {
        count++;
        if (count == k) {
            prev = reverse(prev, head->next);
            head = prev->next;
            count = 0;
        } else {
            head = head->next;
        }
    }
    return dummyHead->next;
}