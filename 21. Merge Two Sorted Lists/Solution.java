/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(Integer.MIN_VALUE);
        dummyHead.next = l1;
        
        ListNode pre = dummyHead;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val)
                l1 = l1.next;
            else {
                ListNode l2next = l2.next;
                l2.next = l1;
                pre.next = l2;
                
                l2 = l2next;
            }
            
            pre = pre.next;
        }
        
        if (l2 != null)
            pre.next = l2;
            
        return dummyHead.next;
    }
}