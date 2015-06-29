# LeetCode #206: Reverse Linked List

'''
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution: # Recursion
    def reverseList(self, head):
        if head is None or head.next is None:
            return head
            
        rest = head.next
        head.next = None
        
        reverseRest = self.reverseList(rest)
        rest.next = head
        
        return reverseRest

class Solution: # Iteration
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if head == None or head.next == None:
            return head
            
        prev = None
        curr = head
        while curr != None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        head = prev
        return head
        