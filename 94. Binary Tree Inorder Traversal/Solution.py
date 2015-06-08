# LeetCode #94: Binary Tree Inorder Traversal

'''
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def inorderTraversal(self, root):
        if root == None:
            return []
            
        stack = []
        res = []
        
        curr = root
        while curr != None or len(stack) > 0:
            if curr != None:
                stack.append(curr)
                curr = curr.left
            else:
                temp = stack.pop()
                res.append(temp.val)
                curr = temp.right
        return res
        