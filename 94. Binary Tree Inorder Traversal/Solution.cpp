// LeetCode #94: Binary Tree Inorder Traversal

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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