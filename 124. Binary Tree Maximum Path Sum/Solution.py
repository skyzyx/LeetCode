# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def maxPathSum(self, root):
        if root == None:
            return 0
        res = [-(1 << 31)] # Not res = []
        self.dfs(root, res);
        return res[0]
        
    def dfs(self, root, res):
        if root == None:
            return 0
            
        left = self.dfs(root.left, res)
        right = self.dfs(root.right, res)
        
        arch = left + right + root.val
        single = max(root.val, max(left, right) + root.val)
        
        res[0] = max(res[0], max(arch, single));
        return single # Not return res[0]