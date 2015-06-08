// LeetCode #23: Merge k Sorted Lists

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
            
        return mergeSort(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            return merge(mergeSort(lists, l, m), mergeSort(lists, m+1, r));
        }
        return lists[l];
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = l1;
        
        ListNode* pre = dummyHead;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val)
                l1 = l1->next;
            else {
                ListNode* l2next = l2->next;
                pre->next = l2;
                l2->next = l1;
                
                l2 = l2next;
            }
            
            pre = pre->next;
        }
        
        if (l2 != NULL)
            pre->next = l2;
            
        return dummyHead->next;
    }
};