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