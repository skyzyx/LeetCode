# LeetCode #107: Binary Tree Level Order Traversal II

'''
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrderBottom(self, root):
        if root == None:
            return []
            
        que = deque([root])
        res = []
        
        while len(que) > 0:
            size = len(que)
            curr = []
            
            for i in xrange(size):
                tmp = que.popleft()
                curr.append(tmp.val)
                
                if tmp.left != None:
                    que.append(tmp.left)
                if tmp.right != None:
                    que.append(tmp.right)
            res.insert(0, curr)
        return res
                
        