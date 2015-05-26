/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
            
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        struct ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
 
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
            
    struct ListNode* runner = head;
    struct ListNode* walker = head;
    while (runner->next != NULL && runner->next->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
    }
        
    struct ListNode* rightHalf = reverseList(walker->next);
    walker->next = NULL;
        
    while (rightHalf != NULL) {
        struct ListNode* tmp = rightHalf;
        rightHalf = rightHalf->next;
            
        tmp->next = head->next;
        head->next = tmp;
        head = head->next->next;
    }
    
    return;
}