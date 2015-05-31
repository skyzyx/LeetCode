# LeetCode #114: Flatten Binary Tree to Linked List

'''
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''
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
'''

class Solution:
    def flatten(self, root):
        if root == None:
            return
        
        stack = [root]
        pre = None
        
        while len(stack) > 0:
            cur = stack.pop()
            if cur.right != None:
                stack.append(cur.right)
            if cur.left != None:
                stack.append(cur.left)
                
            if pre != None:
                pre.left = None
                pre.right = cur
                
            pre = cur
        return
