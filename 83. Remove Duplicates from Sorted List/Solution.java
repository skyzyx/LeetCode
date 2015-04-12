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