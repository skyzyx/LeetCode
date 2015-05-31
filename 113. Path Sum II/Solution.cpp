// LeetCode #113: Path Sum II

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

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