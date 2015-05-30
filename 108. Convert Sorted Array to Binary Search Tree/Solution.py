# LeetCode #108: Convert Sorted Array to Binary Search Tree

# Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        return self.dfs(num, 0, len(num) - 1)
        
    def dfs(self, num, left, right):
        if left > right:
            return None
        
        mid = (left + right) / 2
        root = TreeNode(num[mid]) # NOT root = new TreeNode(num[mid])
        root.left = self.dfs(num, left, mid - 1)
        root.right = self.dfs(num, mid + 1, right)
        return root
        
        