# LeetCode #147: Insertion Sort List

# Sort a linked list using insertion sort.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def insertionSortList(self, head):
        if head == None or head.next == None:
            return head
            
        cur = head.next
        while cur != None:
            tmp = head
            while cur != tmp:
                if cur.val < tmp.val:
                    data = cur.val
                    cur.val = tmp.val
                    tmp.val = data
                
                tmp = tmp.next
            
            cur = cur.next
        return head