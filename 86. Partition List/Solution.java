/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null)
            return head;
            
        ListNode h1 = new ListNode(Integer.MIN_VALUE);
        h1.next = head;
        head = h1;
        
        ListNode h2 = new ListNode(Integer.MIN_VALUE);
        ListNode t2 = h2;
        
        while (head.next != null) {
            if (head.next.val < x)
                head = head.next;
            else {
                t2.next = head.next;
                head.next = head.next.next;
                
                t2 = t2.next;
                t2.next = null;
            }
        }
        
        head.next = h2.next;
        return h1.next;
    }
}