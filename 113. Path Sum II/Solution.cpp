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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
            
        vector<int> cur;
        dfs(root, cur, res, sum);
        return res;
    }
    
private:
    void dfs(TreeNode* root, vector<int> &cur, vector<vector<int>> &res, int sum) {
        if (root == NULL)
            return;
            
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        
        if (root->left != NULL) {
            cur.push_back(root->val);
            dfs(root->left, cur, res, sum - root->val);
            cur.pop_back();
        }
        
        if (root->right != NULL) {
            cur.push_back(root->val);
            dfs(root->right, cur, res, sum - root->val);
            cur.pop_back();
        }
    }
};