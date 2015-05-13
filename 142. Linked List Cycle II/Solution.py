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
            
        walker = head
        runner = head
        hasCircle = False
        
        while runner != None and runner.next != None:
            runner = runner.next.next
            walker = walker.next
            if runner == walker:
                hasCircle = True
                break
            
        if hasCircle:
            runner = head
            while runner != walker:
                runner = runner.next
                walker = walker.next
            return runner
            
        return None
        