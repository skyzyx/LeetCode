/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)
            return;
            
        ListNode runner = head;
        ListNode walker = head;
        while (runner.next != null && runner.next.next != null) {
            runner = runner.next.next;
            walker = walker.next;
        }
        
        ListNode right = reverseList(walker.next); // Reverse the second half list from this node.
        
        walker.next = null; // The end of the first half list.
        
        while (right != null) { // Merge the left half and right half.
            ListNode temp = right;
            right = right.next;
            
            temp.next = head.next;
            head.next = temp;
            head = head.next.next;
        }
        
        return;
    }
    
    private ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}