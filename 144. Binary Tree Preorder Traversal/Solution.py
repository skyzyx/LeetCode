# LeetCode #144: Binary Tree Preorder Traversal

'''
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution: # Recursion
    def preorderTraversal(self, root):
        res = []
        if root is None:
            return res
            
        res.append(root.val)
        res.extend(self.preorderTraversal(root.left))
        res.extend(self.preorderTraversal(root.right))
        
        return res

'''
class Solution: # Iteration
    # @param {TreeNode} root
    # @return {integer[]}
    def preorderTraversal(self, root):
        if root == None:
            return []
            
        stack = [root]
        res = []
        
        while len(stack) > 0:
            tmp = stack.pop()
            res.append(tmp.val)
            
            if tmp.right != None:
                stack.append(tmp.right)
            if tmp.left != None:
                stack.append(tmp.left)
        return res
'''           