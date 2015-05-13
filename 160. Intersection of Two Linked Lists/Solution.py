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