/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p != NULL && q != NULL && p->val == q->val)
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    return false;
}


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return dfs(root->left, root->right);
}