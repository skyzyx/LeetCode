/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null)
            return null;
            
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        
        ListNode helper = dummyHead;
        
        while (helper.next != null) {
            if (helper.next.val == val) {
                ListNode foo = helper.next;
                helper.next = foo.next;
            } else {
                helper = helper.next;
            }
        }
        return dummyHead.next;
    }
}