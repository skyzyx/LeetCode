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
            
        ListNode walker = head;
        ListNode runner = head;
        boolean hasCircle = false;
        
        while (runner != null && runner.next != null) {
            walker = walker.next;
            runner = runner.next.next;
            if (walker == runner) {
                hasCircle = true;
                break;
            }
        }
        
        if (hasCircle == true) {
            runner = head;
            while (walker != runner) {
                runner = runner.next;
                walker = walker.next;
            }
            return runner;
        }
        
        return null;
    }
}