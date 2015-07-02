// LeetCode #95: Unique Binary Search Trees II

/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode *> helper(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftSubTrees = helper(start, i-1);
            vector<TreeNode *> rightSubTrees = helper(i+1, end);
            
            for (int j = 0; j < leftSubTrees.size(); j++) {
                for (int k = 0; k < rightSubTrees.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubTrees[j];
                    root->right = rightSubTrees[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};