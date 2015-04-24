# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        if head == None:
            return None
        
        dummyHead = ListNode(-1)
        dummyHead.next = head
        
        helper = dummyHead
        while helper.next != None:
            if helper.next.val == val:
                fooNode = helper.next
                helper.next = fooNode.next
            else:
                helper = helper.next
        
        return dummyHead.next