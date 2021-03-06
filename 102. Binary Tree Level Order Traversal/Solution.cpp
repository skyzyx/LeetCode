/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
            
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            
            for (int i = 0; i < size; i++) {
                TreeNode* foo = que.front();
                que.pop();
                
                tmp.push_back(foo->val);
                if (foo->left != NULL)
                    que.push(foo->left);
                if (foo->right != NULL)
                    que.push(foo->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};