# LeetCode #173: Binary Search Tree Iterator

'''
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
'''

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator: # Inorder traversal
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.inorder = []
        self.inorderTraversal(root)
        self.index = -1
        self.size = len(self.inorder)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        self.index += 1
        return self.index < self.size

    # @return an integer, the next smallest number
    def next(self):
        return self.inorder[self.index]
        
    def inorderTraversal(self, root):
        if root is None:
            return
        
        self.inorderTraversal(root.left)
        self.inorder.append(root.val)
        self.inorderTraversal(root.right)

'''
class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.stack) != 0

    # @return an integer, the next smallest number
    def next(self):
        curr = self.stack.pop()
        data = curr.val
        
        if curr.right is not None:
            curr = curr.right
            while curr is not None:
                self.stack.append(curr)
                curr = curr.left
                
        return data
'''

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())