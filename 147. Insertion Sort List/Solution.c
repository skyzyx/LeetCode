// LeetCode #147: Insertion Sort List

// Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
            
    struct ListNode* cur = head->next;
    while (cur != NULL) {
        struct ListNode* tmp = head;
        while (tmp != cur) {
            if (tmp->val > cur->val) {
            int data = cur->val;
                cur->val = tmp->val;
                tmp->val = data;
            }
            tmp = tmp->next;
        }
        cur = cur->next;
    }
    return head;
}