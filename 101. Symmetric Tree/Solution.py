# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isSymmetric(self, root):
        if root == None:
            return True
        return self.dfs(root.left, root.right)
        
    def dfs(self, p, q):
        if p == None and q == None:
            return True
        if p != None and q != None and p.val == q.val:
            return self.dfs(p.left, q.right) and self.dfs(p.right, q.left)
        return False