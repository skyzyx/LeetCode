# LeetCode #113: Path Sum II

'''
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
'''

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        res = []
        if root == None:
            return res
            
        cur = []
        self.dfs(root, cur, res, sum)
        return res
        
    def dfs(self, root, cur, res, sum):
        if root == None:
            return
        
        if root.left == None and root.right == None and root.val == sum:
            cur.append(root.val)
            res.append(list(cur)) # Create a new object.
            cur.pop()
            return
        
        if root.left != None:
            cur.append(root.val)
            self.dfs(root.left, cur, res, sum - root.val)
            cur.pop()
            
        if root.right != None:
            cur.append(root.val)
            self.dfs(root.right, cur, res, sum - root.val)
            cur.pop()
        