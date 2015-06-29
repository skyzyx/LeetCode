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
class Solution { // Recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        vector<int> left = inorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        
        res.push_back(root->val);
        
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end()); // NOT res.push_back(inorderTraversal(root->left));
        // no matching function for call to ‘std::vector<int>::push_back(std::vector<int>)    
        
        return res;
    }
}; 

/*
class Solution { // Iterative
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
*/