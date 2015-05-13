/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null || m >= n)
            return head;
            
        ListNode dummyHead = new ListNode(Integer.MIN_VALUE);
        dummyHead.next = head;
        
        head = dummyHead;
        
        for (int i = 0; i < m-1; i++)
            head = head.next;
            
        ListNode pre = head.next;
        ListNode cur = head.next.next;
        
        for (int i = 0; i < n-m; i++) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        
        head.next.next = cur;
        head.next = pre;
        
        return dummyHead.next;
    }
}