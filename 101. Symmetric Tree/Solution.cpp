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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }

private:    
    bool helper(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL)
            return true;
        if (node1 == NULL || node2 == NULL)
            return false;
        if (node1->val != node2->val)
            return false;
        return helper(node1->left, node2->right) && helper(node1->right, node2->left);
    } 
};