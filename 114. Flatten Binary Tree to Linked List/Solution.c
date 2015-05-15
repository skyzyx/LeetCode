/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;
        
    if (root->left != NULL) {
        struct TreeNode* leftNode = root->left;
        struct TreeNode* rightNode = root->right;
        
        root->left = NULL;
        root->right = leftNode;
        
        struct TreeNode* p = root->right;
        while (p->right != NULL)
            p = p->right;
            
        p->right = leftNode;
    }
    
    flatten(root->right);
}