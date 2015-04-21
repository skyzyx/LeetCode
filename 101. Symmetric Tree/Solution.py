# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isSymmetric(self, root):
        if root == None:
            return True;
        return self.helper(root.left, root.right)
        
    def helper(self, node1, node2):
        if node1 == None and node2 == None:
            return True
        if node1 == None or node2 == None:
            return False
        if node1.val != node2.val:
            return False
        return self.helper(node1.left, node2.right) and self.helper(node1.right, node2.left)
        