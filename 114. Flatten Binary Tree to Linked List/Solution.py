# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {void} Do not return anything, modify root in-place instead.
    def flatten(self, root):
        if root == None:
            return
        
        if root.left != None:
            leftNode = root.left
            rightNode = root.right
            
            root.left = None
            root.right = leftNode
            
            p = root.right
            while p.right != None:
                p = p.right
                
            p.right = rightNode
            
        self.flatten(root.right)