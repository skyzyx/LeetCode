// LeetCode #148: Sort List

// Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        return mergeSort(head);
    }
    
private:
    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* walker = head;
        ListNode* runner = head;
        while (runner->next != NULL && runner->next->next != NULL) {
            runner = runner->next->next;
            walker = walker->next;
        }
        
        ListNode* head2 = walker->next;
        walker->next = NULL;
        
        ListNode* head1 = head;
        
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return merge(head1, head2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = l1;
        
        ListNode* pre = dummyHead;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val)
                l1 = l1->next;
            else {
                ListNode* next = l2->next;
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
};