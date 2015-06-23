// LeetCode #226: Invert Binary Tree

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
            
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            
            if (curr->left != NULL)
                que.push(curr->left);
            if (curr->right != NULL)
                que.push(curr->right);
                
            TreeNode* temp = curr->right;
            curr->right = curr->left;
            curr->left = temp;
        }
        return root;
    }
};

/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
            
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};
*/