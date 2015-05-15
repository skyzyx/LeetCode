# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode[]} lists
    # @return {ListNode}
    def mergeKLists(self, lists):
        if lists == None or len(lists) == 0:
            return None
            
        return self.mergeSort(lists, 0, len(lists) - 1)
        
    def mergeSort(self, lists, l, r):
        if l < r:
            m = (l+r)/2
            return self.merge(self.mergeSort(lists, l, m), self.mergeSort(lists, m+1, r))
        return lists[l]
        
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