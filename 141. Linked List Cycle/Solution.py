# LeetCode #141: Linked List Cycle

'''
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if head == None or head.next == None:
            return False
            
        runner = head
        walker = head
        while runner != None and runner.next != None:
            walker = walker.next
            runner = runner.next.next
            if walker == runner:
                return True
        return False
        