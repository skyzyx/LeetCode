# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {void} Do not return anything, modify head in-place instead.
    def reorderList(self, head):
        if head == None or head.next == None or head.next.next == None:
            return
        
        walker = head
        runner = head
        while runner.next != None and runner.next.next != None:
            walker = walker.next
            runner = runner.next.next
            
        right = self.reverseList(walker.next)
        walker.next = None
        
        while right != None:
            tmp = right
            right = right.next
            
            tmp.next = head.next
            head.next = tmp
            head = head.next.next
            
        return
    
    def reverseList(self, head):
        if head == None or head.next == None:
            return head
            
        pre = None
        cur = head
        while cur != None:
            tmp = cur.next
            
            cur.next = pre
            pre = cur
            cur = tmp
        return pre