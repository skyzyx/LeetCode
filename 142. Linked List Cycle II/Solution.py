# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if head == None or head.next == None:
            return None
            
        walker = head.next
        runner = head.next.next
        while runner != None and runner != walker:
            walker = walker.next
            if runner.next != None:
                runner = runner.next.next
            else:
                runner = None
        
        if runner == None:
            return None
            
        runner = head
        while runner != walker:
            runner = runner.next
            walker = walker.next
        return runner
        