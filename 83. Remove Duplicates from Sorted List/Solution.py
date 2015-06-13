# LeetCode #83: Remove Duplicates from Sorted List

'''
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
            
        p = head
        while p.next != None:
            if p.val == p.next.val:
                p.next =  p.next.next;
            else:
                p = p.next
        return head;

'''
class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
            
        pre = head
        cur = head.next
        while cur != None:
            if pre.val == cur.val:
                pre.next = cur.next
            else:
                pre = cur
                
            cur = cur.next
        return head
'''