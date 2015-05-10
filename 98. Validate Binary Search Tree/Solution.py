# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import sys

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isValidBST(self, root):
        if root == None:
            return True
        return self.dfs(root, -(1 << 63), 1 << 63)
        
    def dfs(self, root, left, right):
        if root == None:
            return True
        if root.val <= left or root.val >= right:
            return False
        return self.dfs(root.left, left, root.val) and self.dfs(root.right, root.val, right)