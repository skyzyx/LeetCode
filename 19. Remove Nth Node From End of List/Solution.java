// LeetCode #19: Remove Nth Node From End of List

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n == 0)
            return head;
            
        ListNode runner = head;
        ListNode walker = head;
        
        for (int i = 0; i < n; i++)
            if (runner != null)
                runner = runner.next;
                
        if (runner == null)
            return head.next; // n == size(list), needs to delete the head.
            
        while (runner.next != null) {
            runner = runner.next;
            walker = walker.next;
        }
        
        walker.next = walker.next.next;
        return head;
    }
}