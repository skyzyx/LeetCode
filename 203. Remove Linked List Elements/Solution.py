# LeetCode #203: Remove Linked List Elements

'''
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        if head == None:
            return head
            
        dummyHead = ListNode(-1)
        dummyHead.next = head
        
        p = dummyHead
        while p.next != None:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        return dummyHead.next