/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
            
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* pre = NULL;
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            
            if (cur->right != NULL)
                s.push(cur->right);
                
            if (cur->left != NULL)
                s.push(cur->left);
                
            if (pre != NULL) {
                pre->left = NULL;
                pre->right = cur;
            }
            
            pre = cur;
        }
        return;
    }
};

/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
            
        if (root->left != NULL) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;
            
            root->left = NULL;
            root->right = leftSubTree;
            
            TreeNode* p = root->right;
            while (p->right != NULL)
                p = p->right;
                
            p->right = rightSubTree;
        }
        
        flatten(root->right);
    }
};
*/