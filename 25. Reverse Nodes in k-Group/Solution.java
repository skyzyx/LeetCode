// LeetCode #25: Reverse Nodes in k-Group

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k < 2)
            return head;
            
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode prev = dummy;
        
        int count = 0;
        while (head != null) {
            count++;
            if (count == k) {
                prev = reverse(prev, head.next);
                head = prev.next;
                count = 0;
            } else {
                head = head.next;
            }
        }
        return dummy.next;
    }
    
    private ListNode reverse(ListNode prev, ListNode next) { // Reverse nodes between prev and next, does NOT include prev and next.
        ListNode last = prev.next;
        ListNode curr = last.next;
        
        while (curr != next) {
            last.next = curr.next;
            curr.next = prev.next;
            prev.next = curr;
            
            curr = last.next;
        }
        return last;
    }
}