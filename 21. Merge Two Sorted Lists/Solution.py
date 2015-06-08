# LeetCode #21: Merge Two Sorted Lists

# Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        dummyHead = ListNode(-1)
        dummyHead.next = l1
        
        pre = dummyHead
        
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                l1 = l1.next
            else:
                l2next = l2.next
                pre.next = l2
                l2.next = l1
                
                l2 = l2next
            
            pre = pre.next
            
        if l2 != None:
            pre.next = l2
            
        return dummyHead.next