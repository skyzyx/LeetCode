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