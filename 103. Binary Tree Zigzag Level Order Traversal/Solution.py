'''
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def zigzagLevelOrder(self, root):
        if root == None:
            return []
            
        stackCurr = [root]
        res = []
        direction = True
        
        while len(stackCurr) > 0:
            size = len(stackCurr)
            tmpList = []
            stackNext = []
            
            for i in xrange(size):
                node = stackCurr.pop()
                tmpList.append(node.val)
                
                if direction == True:
                    if node.left != None:
                        stackNext.append(node.left)
                    if node.right != None:
                        stackNext.append(node.right)
                else:
                    if node.right != None:
                        stackNext.append(node.right)
                    if node.left != None:
                        stackNext.append(node.left)
            
            direction = ~direction
            res.append(tmpList)
            stackCurr = stackNext
            
        return res