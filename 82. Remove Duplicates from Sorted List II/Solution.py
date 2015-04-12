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
            
        