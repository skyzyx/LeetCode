'''
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    def levelOrder(self, root):
        if root == None:
            return []
            
        queue = deque([root]) # How to define a queue in python, from collections import deque.
        res = []
        
        while len(queue) > 0:
            size = len(queue)
            cur = []
            
            for i in xrange(size):
                tmp = queue.popleft() # popleft(), not pop().
                cur.append(tmp.val)
                
                if tmp.left != None:
                    queue.append(tmp.left)
                if tmp.right != None:
                    queue.append(tmp.right)
            res.append(cur)
        return res
            
        