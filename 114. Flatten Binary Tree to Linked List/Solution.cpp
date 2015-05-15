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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
            
        if (root->left != NULL) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;
            
            root->left = NULL;
            root->right = leftSubTree;
            
            TreeNode* p = root->right;
            while (p->right != NULL)
                p = p->right;
                
            p->right = rightSubTree;
        }
        
        flatten(root->right);
    }
};