# LeetCode #199: Binary Tree Right Side View

'''
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
'''

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        res = [];
        if root is None:
            return res
        
        que = deque([root])
        while que:
            size = len(que);
            for i in range(0, size):
                tmp = que.popleft()
                if i == 0:
                    res.append(tmp.val)
                if tmp.right:
                    que.append(tmp.right)
                if tmp.left:
                    que.append(tmp.left)
        return res

'''
class Solution:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        res = [];
        if root is None:
            return res
        
        que = [root]
        while que:
            size = len(que);
            for i in range(0, size):
                tmp = que.pop(0) # Not que.pop()
                if i == 0:
                    res.append(tmp.val)
                if tmp.right:
                    que.append(tmp.right)
                if tmp.left:
                    que.append(tmp.left)
        return res
'''