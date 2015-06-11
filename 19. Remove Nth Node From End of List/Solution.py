# LeetCode #19: Remove Nth Node From End of List

'''
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        if head == None or n == 0:
            return head
            
        runner = head
        walker = head
        for i in xrange(n):
            if runner != None:
                runner = runner.next
             
        
        #Runtime Error Message:	Line 24: AttributeError: 'NoneType' object has no attribute 'next'
        #Last executed input:	[1], 1        
        if runner == None:
            return head.next
        
        while runner.next != None:
            runner = runner.next
            walker = walker.next
            
        walker.next = walker.next.next
        return head