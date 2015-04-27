# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        if root == None:
            return 0
            
        cur = 0;
        res = [0]
        self.getSum(root, cur, res)
        return res[0]
        
    def getSum(self, root, cur, res):
        if root == None:
            return
        
        cur = cur * 10 + root.val
        if root.left == None and root.right == None:
            res[0] += cur
            return
        
        self.getSum(root.left, cur, res)
        self.getSum(root.right, cur, res)