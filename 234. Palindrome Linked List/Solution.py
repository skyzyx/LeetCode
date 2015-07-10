# LeetCode #234: Palindrome Linked List

'''
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        if head is None or head.next is None:
            return True
            
        stack = []
        p = head
        
        while p is not None:
            stack.append(p)
            p = p.next
            
        while len(stack) != 0:
            curr = stack.pop()
            if curr.val != head.val:
                return False
            head = head.next
            
        return True