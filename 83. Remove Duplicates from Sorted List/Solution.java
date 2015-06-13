// LeetCode #83: Remove Duplicates from Sorted List

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode p = head;
        while (p.next != null) {
            if (p.val == p.next.val)
                p.next = p.next.next;
            else
                p = p.next;
        }
        return head;
    }
}

/* 
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode pre = head;
        ListNode cur = head.next;
        
        while (cur != null) {
            if (pre.val != cur.val)
                pre = cur;
            else
                pre.next = cur.next;
                
            cur = cur.next;
        }
        return head;
    }
}
*/