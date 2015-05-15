/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        return mergeSort(head);
    }
    
    private ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null)
            return head;
            
        ListNode walker = head;
        ListNode runner = head;
        while (runner.next != null && runner.next.next != null) {
            runner = runner.next.next;
            walker = walker.next;
        }
        
        ListNode head2 = walker.next;
        walker.next = null;
        
        ListNode head1 = head;
        
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return merge(head1, head2);
    }
    
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(Integer.MIN_VALUE);
        dummyHead.next = l1;
        
        ListNode pre = dummyHead;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val)
                l1 = l1.next;
            else {
                ListNode next = l2.next;
                pre.next = l2;
                l2.next = l1;
                
                l2 = next;
            }
            
            pre = pre.next;
        }
        
        if (l2 != null)
            pre.next = l2;
            
        return dummyHead.next;
    }
}