// LeetCode #98: Validate Binary Search Tree

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool dfs(struct TreeNode* root, long min, long max) {
    if (root == NULL)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return dfs(root, LONG_MIN, LONG_MAX);
}