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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
            
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            res.insert(res.begin(), tmp->val); //NOT res.push_back(res.begin(), tmp->val);
            
            if (tmp->left != NULL)
                s.push(tmp->left);
            if (tmp->right != NULL)
                s.push(tmp->right);
        }
        return res;
    }
};