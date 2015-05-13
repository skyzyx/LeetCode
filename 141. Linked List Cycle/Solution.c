/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
        
    struct ListNode* runner = head;
    struct ListNode* walker = head;
    
    while (runner != NULL && runner->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
        if (runner == walker)
            return true;
    }
    return false;
}