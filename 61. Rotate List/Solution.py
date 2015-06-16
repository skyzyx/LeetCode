# LeetCode #61: Rotate List

'''
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def rotateRight(self, head, k):
        if head == None or k < 1:
            return head
            
        size = 1
        p = head
        while p.next != None:
            p = p.next
            size += 1
            
        p.next = head
        
        step = size - k % size
        while step > 0:
            p = p.next
            step -= 1
            
        head = p.next
        p.next = None
        return head