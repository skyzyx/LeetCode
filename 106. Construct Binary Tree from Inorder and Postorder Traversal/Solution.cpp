// LeetCode #106: Construct Binary Tree from Inorder and Postorder Traversal

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return dfs(map, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
private:
    TreeNode* dfs(unordered_map<int, int>& map, vector<int>& inorder, int inL, int inR, vector<int>& postorder, int posL, int posR) {
        if (inL > inR || posL > posR)
            return NULL;
            
        TreeNode* root = new TreeNode(postorder[posR]);
        int rootIndex = map[postorder[posR]];
        
        root->left = dfs(map, inorder, inL, rootIndex - 1, postorder, posL, posL+rootIndex-inL-1);
        root->right = dfs(map, inorder, rootIndex+1, inR, postorder, posR+rootIndex-inR, posR-1);
        return root;
    }
};