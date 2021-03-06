# LeetCode #226: Invert Binary Tree

'''
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def invertTree(self, root):
        if root == None:
            return root
            
        que = deque([root])
        while len(que) > 0:
            curr = que.popleft();
            if curr.left != None:
                que.append(curr.left)
            if curr.right != None:
                que.append(curr.right)
                
            temp = curr.right
            curr.right = curr.left
            curr.left = temp
            
        return root

'''
class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root == None:
            return root
            
        left = root.left
        right = root.right
        
        root.left = self.invertTree(right)
        root.right = self.invertTree(left)
        return root
'''