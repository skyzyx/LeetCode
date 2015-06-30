// LeetCode #144: Binary Tree Preorder Traversal

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

class Solution { // Recursion
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
            
        res.push_back(root->val);
        
        vector<int> left = preorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        
        vector<int> right = preorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};

/*
class Solution { // Iteration
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
            
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            
            res.push_back(tmp->val);
            
            if (tmp->right != NULL)
                s.push(tmp->right);
            if (tmp->left != NULL)
                s.push(tmp->left);
        }
        return res;
    }
};
*/