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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        
        ListNode dummyHead = new ListNode(0);
        ListNode res = dummyHead;
            
        int carry = 0;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                carry += l1.val;
                l1 = l1.next;
            }
            
            if (l2 != null) {
                carry += l2.val;
                l2 = l2.next;
            }
            
            res.next = new ListNode(carry % 10);
            res = res.next;
            carry /= 10;
        }
        
        if (carry == 1)
            res.next = new ListNode(1);
        return dummyHead.next;
    }
}