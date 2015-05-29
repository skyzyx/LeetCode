/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
            
        stack<TreeNode*> curr;
        curr.push(root);
        bool direction = true;
        
        while (!curr.empty()) {
            int size = curr.size();
            vector<int> tmp; // NOT vector<Integer> tmp
            stack<TreeNode*> next;
            
            for (int i = 0; i < size; i++) {
                TreeNode* foo = curr.top();
                curr.pop();
                tmp.push_back(foo->val);
                
                if (direction) {
                    if (foo->left != NULL)
                        next.push(foo->left);
                    if (foo->right != NULL)
                        next.push(foo->right);
                } else {
                    if (foo->right != NULL)
                        next.push(foo->right);
                    if (foo->left != NULL)
                        next.push(foo->left);
                }
            }
            res.push_back(tmp);
            direction = !direction;
            curr = next;
        }
        return res;
    }
};