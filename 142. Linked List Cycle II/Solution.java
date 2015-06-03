// LeetCode #142: Linked List Cycle II

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

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