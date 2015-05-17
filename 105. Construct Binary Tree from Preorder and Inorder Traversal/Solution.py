# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {integer[]} preorder
    # @param {integer[]} inorder
    # @return {TreeNode}
    def buildTree(self, preorder, inorder):
        if preorder == None or inorder == None:
            return None
            
        dict_tree = {}
        for i in xrange(len(inorder)):
            dict_tree[inorder[i]] = i
        return self.dfs(dict_tree, preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
        
    def dfs(self, dict_tree, preorder, preL, preR, inorder, inL, inR):
        if preL > preR or inL > inR:
            return None
        
        root = TreeNode(preorder[preL])
        rootIndex = dict_tree[preorder[preL]]
        
        root.left = self.dfs(dict_tree, preorder, preL+1, rootIndex+preL-inL, inorder, inL, rootIndex-1);
        root.right = self.dfs(dict_tree, preorder, preL+rootIndex+1-inL, preR, inorder, rootIndex+1, inR);
        return root