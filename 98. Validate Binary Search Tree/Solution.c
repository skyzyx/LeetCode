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