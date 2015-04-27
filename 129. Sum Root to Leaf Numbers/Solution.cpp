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
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
            
        int res[1] = {0};
        int cur = 0;
        getSum(root, cur, res);
        return res[0];
    }
    
private:
    void getSum(TreeNode* root, int cur, int* res) {
        if (root == NULL)
            return;
            
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            res[0] += cur;
            return;
        }
        
        getSum(root->left, cur, res);
        getSum(root->right, cur, res);
    }
};