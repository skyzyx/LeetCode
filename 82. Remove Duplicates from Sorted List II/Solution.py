# LeetCode #82: Remove Duplicates from Sorted List II

'''
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
            
        dummyHead = ListNode(0)
        dummyHead.next = head
        
        pre = dummyHead
        cur = head
        
        while cur != None:
            while cur.next != None and pre.next.val == cur.next.val:
                cur = cur.next
            
            if pre.next == cur:
                pre = pre.next
            else:
                pre.next = cur.next
                
            cur = cur.next
            
        return dummyHead.next
            
        