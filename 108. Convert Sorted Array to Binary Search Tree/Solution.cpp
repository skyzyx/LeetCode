// LeetCode #108: Convert Sorted Array to Binary Search Tree

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size() - 1);
    }
    
    TreeNode* dfs(vector<int> &num, int left, int right) {
        if (left > right)
            return NULL;
            
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = dfs(num, left, mid - 1);
        root->right = dfs(num, mid + 1, right);
        return root;
    }
};