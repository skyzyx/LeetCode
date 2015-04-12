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
            
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        
        ListNode pre = dummyHead;
        ListNode cur = head;
        
        while (cur != null) {
            while (cur.next != null && pre.next.val == cur.next.val)
                cur = cur.next;
                
            if (pre.next == cur)
                pre = pre.next;
            else
                pre.next = cur.next;
                
            cur = cur.next;
        }
        
        return dummyHead.next;
        
    }
}