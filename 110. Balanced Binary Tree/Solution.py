# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        if root == None:
            return True
        leftHeight = self.getHeight(root.left)
        rightHeight = self.getHeight(root.right)
        diff = abs(leftHeight - rightHeight)
        
        if diff <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right):
            return True
        return False
        
        
    def getHeight(self, root):
        if root == None:
            return 0
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        