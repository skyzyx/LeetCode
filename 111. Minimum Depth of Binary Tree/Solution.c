/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
        
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    
    if (lh == 0)
        return 1 + rh;
    if (rh == 0)
        return 1 + lh;
        
    if (lh > rh)
        return 1 + rh;
    else
        return 1 + lh;
}