# LeetCode #129: Sum Root to Leaf Numbers

'''
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
'''

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