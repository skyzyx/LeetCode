/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null)
            return null;
            
        ListNode walker = head.next;
        ListNode runner = head.next.next;
        while (runner != null && walker != runner) {
            walker = walker.next;
            if (runner.next != null) 
                runner = runner.next.next;
            else 
                runner = null;
        }
        
        if (runner == null)
            return null;
            
        runner = head;
        while (runner != walker) {
            runner = runner.next;
            walker = walker.next;
        }
        
        return runner;
    }
}