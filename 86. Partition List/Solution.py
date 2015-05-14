# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} x
    # @return {ListNode}
    def partition(self, head, x):
        if head == None or head.next == None:
            return head
            
        h1 = ListNode(0)
        h1.next = head
        head = h1
        
        h2 = ListNode(0)
        t2 = h2
        
        while head.next != None:
            if head.next.val < x:
                head = head.next
            else:
                t2.next = head.next
                head.next = head.next.next
                t2 = t2.next
                t2.next = None
                
        head.next = h2.next
        return h1.next