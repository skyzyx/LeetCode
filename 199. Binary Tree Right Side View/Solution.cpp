// LeetCode #199: Binary Tree Right Side View

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        queue<TreeNode*> que; 
        que.push(root);
        
        while(!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                
                if (i == 0)
                    res.push_back(tmp->val);
                if (tmp->right != NULL)
                    que.push(tmp->right);
                if (tmp->left != NULL)
                    que.push(tmp->left);
            }
        }
        return res;
    }
};