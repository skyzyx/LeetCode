# LeetCode #98: Validate Binary Search Tree

'''
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
'''

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