// LeetCode #110: Balanced Binary Tree

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    if (l > r)
        return 1 + l;
    else
        return 1 + r;
} 
 
bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
        
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int diff = abs(leftHeight - rightHeight);
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}