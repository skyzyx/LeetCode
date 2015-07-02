# LeetCode #95: Unique Binary Search Trees II

'''
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @return a list of tree node
    def generateTrees(self, n):
        return self.helper(1, n);
        
    def helper(self, start, end): # Not def helper(start, end)
        res = [];
        if start > end:
            res.append(None)
            return res
            
        for i in range(start, end+1):
            leftSubTrees = self.helper(start, i-1)
            rightSubTrees = self.helper(i+1, end)
            
            for left in leftSubTrees:
                for right in rightSubTrees:
                    root = TreeNode(i)
                    root.left = left;
                    root.right = right;
                    res.append(root);
        return res
        