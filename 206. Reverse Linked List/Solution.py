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

class Solution:
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
        