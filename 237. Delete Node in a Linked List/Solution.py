# LeetCode #237: Delete Node in a Linked List

'''
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} node
    # @return {void} Do not return anything, modify node in-place instead.
    def deleteNode(self, node):
        if node is None:
            return
        
        prev = node
        while node.next is not None:
            data = node.val
            node.val = node.next.val
            node.next.val = data
            
            prev = node
            node = node.next
            
        prev.next = None
        return