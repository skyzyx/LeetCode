/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k < 1)
            return head;
            
        int len = 1;
        ListNode p = head;
        while (p.next != null) {
            p = p.next;
            len++;
        }
        
        p.next = head;
        
        int step = len - k % len;
        while (step > 0) {
            p = p.next;
            step--;
        }
        
        head = p.next;
        p.next = null;
        return head;
    }
}