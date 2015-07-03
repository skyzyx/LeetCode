# LeetCode #230: Kth Smallest Element in a BST

'''
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} k
    # @return {integer}
    def kthSmallest(self, root, k):
        if root is None or k < 0:
            return 0
            
        stack = []
        count = 0
        curr = root
        
        while curr is not None or len(stack) != 0:
            if curr is not None:
                stack.append(curr)
                curr = curr.left
            else:
                temp = stack.pop()
                count += 1
                curr = temp.right
                
                if count == k:
                    return temp.val
        
        return 0