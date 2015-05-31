# LeetCode #117: Populating Next Right Pointers in Each Node II

'''
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
'''

# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root == None:
            return
        
        p = root.next
        while p != None:
            if p.left != None:
                p = p.left
                break
            if p.right != None:
                p = p.right
                break
            
            p = p.next
            
        if root.left != None:
            root.left.next = p if root.right == None else root.right
            
        if root.right != None:
            root.right.next = p
            
        self.connect(root.right)
        self.connect(root.left)
        return