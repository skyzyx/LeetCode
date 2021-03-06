# LeetCode #160: Intersection of Two Linked Lists

'''
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        alen = self.getLength(headA)
        blen = self.getLength(headB)
        
        while alen > blen:
            headA = headA.next
            alen -= 1
            
        while blen > alen:
            headB = headB.next
            blen -= 1
            
        while headA != None and headB != None:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None

    def getLength(self, head):
        if head == None:
            return 0
            
        res = 0
        while head != None:
            head = head.next
            res += 1
        return res