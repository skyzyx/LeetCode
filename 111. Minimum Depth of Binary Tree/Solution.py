# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root == None:
            return 0
            
        leftDepth = self.minDepth(root.left)
        rightDepth = self.minDepth(root.right)
        
        if leftDepth == 0:
            return 1 + rightDepth
        if rightDepth == 0:
            return 1 + leftDepth
        return 1 + min(leftDepth, rightDepth)