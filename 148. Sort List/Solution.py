# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def sortList(self, head):
        if head == None or head.next == None:
            return head
        return self.mergeSort(head)
        
    def mergeSort(self, head):
        if head == None or head.next == None:
            return head
            
        walker = head
        runner = head
        while runner.next != None and runner.next.next != None:
            runner = runner.next.next
            walker = walker.next
            
        head2 = walker.next
        walker.next = None
        
        head1 = head
        
        head2 = self.mergeSort(head2)
        head1 = self.mergeSort(head1)
        return self.merge(head1, head2)
        
    def merge(self, l1, l2):
        dummyHead = ListNode(-1)
        dummyHead.next = l1
        
        pre = dummyHead
        while l1 != None and l2 != None:
            if l1.val < l2.val:
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
            