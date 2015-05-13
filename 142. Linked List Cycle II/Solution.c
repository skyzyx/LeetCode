/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
        
    struct ListNode* walker = head;
    struct ListNode* runner = head;
    bool hasCircle = false;
    
    while (runner != NULL && runner->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
        if (runner == walker) {
            hasCircle = true;
            break;
        }
    }
    
    if (hasCircle) {
        runner = head;
        while (runner != walker) {
            runner = runner->next;
            walker = walker->next;
        }
        return walker;
    }
    
    return NULL;
}