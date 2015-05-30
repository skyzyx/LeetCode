// LeetCode #105: Construct Binary Tree from Preorder and Inorder Traversal 

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return dfs(map, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
private:
    TreeNode* dfs(unordered_map<int, int>& map, vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR) {
        if (preL > preR || inL > inR)
            return NULL;
            
        TreeNode* root = new TreeNode(preorder[preL]);
        int rootIndex = map[preorder[preL]];
        
        root->left = dfs(map, preorder, preL+1, rootIndex+preL-inL, inorder, inL, rootIndex-1);
        root->right = dfs(map, preorder, preL+rootIndex+1-inL, preR, inorder, rootIndex+1, inR);
        return root;
    }
};