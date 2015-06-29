// LeetCode #206: Reverse Linked List

/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution { // Recursion
    public ListNode reverseList(ListNode head){
        if (head == null || head.next == null)
            return head;
        
        ListNode rest = head.next;
        head.next = null;
        
        ListNode reverseRest = reverseList(rest);
        rest.next = head;
        
        return reverseRest;
    }
} 

/*
public class Solution { // Iteration
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode prev = null;
        ListNode curr = head;
        
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
}
*/