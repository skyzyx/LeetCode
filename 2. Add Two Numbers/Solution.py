# LeetCode #2: Add Two Numbers

'''
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
            
        res = ListNode(-1)
        dummyHead = res
        
        carry = 0
        while l1 != None or l2 != None:
            if l1 != None:
                carry += l1.val
                l1 = l1.next
                
            if l2 != None:
                carry += l2.val
                l2 = l2.next
                
            res.next = ListNode(carry % 10)
            res = res.next
            carry /= 10
            
        if carry == 1:
            res.next = ListNode(carry)
            
        return dummyHead.next
                
                