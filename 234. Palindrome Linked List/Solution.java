// LeetCode #234: Palindrome Linked List

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;
            
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        
        ListNode head2 = slow.next;

        ListNode prev = null;
        while (head2 != null) {
            ListNode next = head2.next;
            head2.next = prev;
            prev = head2;
            head2 = next;
        }
        
        ListNode p1 = head;
        ListNode p2 = prev;
        
        while (p2 != null) {
            if (p2.val != p1.val)
                return false;
            p2 = p2.next;
            p1 = p1.next;
        }
        return true;
    }
}

/*
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        
        Stack<ListNode> s = new Stack<ListNode>();
        ListNode p = head;
        while (p != null) {
            s.push(p);
            p = p.next;
        }
        
        while (!s.isEmpty()) {
            ListNode curr = s.pop();
            if (head.val != curr.val) return false;
            head = head.next;
        }
        return true;
    }
}
*/