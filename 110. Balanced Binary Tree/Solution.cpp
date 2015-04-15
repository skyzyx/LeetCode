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
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int diff = abs(leftHeight - rightHeight);
        
        if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
    
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};