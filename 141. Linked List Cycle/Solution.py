# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if head == None or head.next == None:
            return False
            
        runner = head
        walker = head
        while runner != None and runner.next != None:
            walker = walker.next
            runner = runner.next.next
            if walker == runner:
                return True
        return False
        