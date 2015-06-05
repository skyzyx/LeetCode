// LeetCode #147: Insertion Sort List

// Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode cur = head.next;
        while (cur != null) {
            ListNode tmp = head;
            while (cur != tmp) {
                if (cur.val < tmp.val) {
                    int data = cur.val;
                    cur.val = tmp.val;
                    tmp.val = data;
                }
                tmp = tmp.next;
            }
            cur = cur.next;
        }
        return head;
    }
}