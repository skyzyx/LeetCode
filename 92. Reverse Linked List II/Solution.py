# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} m
    # @param {integer} n
    # @return {ListNode}
    def reverseBetween(self, head, m, n):
        if head == None or head.next == None or m >= n:
            return head
            
        dummyHead = ListNode(-1)
        dummyHead.next = head
        
        head = dummyHead
        
        for i in xrange(0, m-1):
            head = head.next
            
        pre = head.next
        cur = head.next.next
        
        for i in xrange(0, n-m):
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
            
        head.next.next = cur
        head.next = pre
        
        return dummyHead.next