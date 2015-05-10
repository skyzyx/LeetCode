# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def preorderTraversal(self, root):
        if root == None:
            return []
            
        stack = [root]
        res = []
        
        while len(stack) > 0:
            tmp = stack.pop()
            res.append(tmp.val)
            
            if tmp.right != None:
                stack.append(tmp.right)
            if tmp.left != None:
                stack.append(tmp.left)
        return res
            