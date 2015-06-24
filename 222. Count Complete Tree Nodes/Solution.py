# LeetCode #222: Count Complete Tree Nodes

'''
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def countNodes(self, root):
        if root == None:
            return 0
            
        leftHeight = 0
        p1 = root
        while p1 != None:
            leftHeight += 1
            p1 = p1.left
            
        rightHeight = 0
        p2 = root
        while p2 != None:
            rightHeight += 1
            p2 = p2.right
            
        if leftHeight == rightHeight:
            return (1 << leftHeight) - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
