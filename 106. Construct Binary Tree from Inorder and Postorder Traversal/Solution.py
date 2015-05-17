# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {integer[]} inorder
    # @param {integer[]} postorder
    # @return {TreeNode}
    def buildTree(self, inorder, postorder):
        if inorder == None or postorder == None:
            return None
            
        dict_tree = {}
        for i in xrange(len(inorder)):
            dict_tree[inorder[i]] = i
        return self.dfs(dict_tree, inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1)
        
    def dfs(self, dict_tree, inorder, inL, inR, postorder, posL, posR):
        if inL > inR or posL > posR:
            return None
        
        root = TreeNode(postorder[posR])
        rootIndex = dict_tree[postorder[posR]]
        
        root.left = self.dfs(dict_tree, inorder, inL, rootIndex - 1, postorder, posL, posL+rootIndex-inL-1);
        root.right = self.dfs(dict_tree, inorder, rootIndex+1, inR, postorder, posR+rootIndex-inR, posR-1);
        return root