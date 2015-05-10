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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
            
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while (cur != NULL || !s.empty()) {
            if (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = s.top();
                s.pop();
                
                res.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return res;
    }
};