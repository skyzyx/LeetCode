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
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
            
        ListNode dummyHead = new ListNode(-1);
        ListNode p = dummyHead;
        
        while (l1 != null && l2 != null) {
            if (l1.val >= l2.val) {
                p.next = l2;
                l2 = l2.next;
            } else {
                p.next = l1;
                l1 = l1.next;
            }
            p = p.next;
        }
        
        if (l1 != null)
            p.next = l1;
        if (l2 != null)
            p.next = l2;
            
        return dummyHead.next;
            
    }
}