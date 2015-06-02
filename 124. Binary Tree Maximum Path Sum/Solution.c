// LeetCode #124: Binary Tree Maximum Path Sum

/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int num1, int num2) {
    return num1 >= num2? num1: num2;
}

int dfs(struct TreeNode* root, int sum[]) {
    if (root == NULL)
        return 0;
            
    int left = dfs(root->left, sum);
    int right = dfs(root->right, sum);
        
    int arch = left + right + root->val;
    int single = max(root->val, max(left, right) + root->val);
        
    sum[0] = max(sum[0], max(arch, single));
    return single;
}

int maxPathSum(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int sum[1] = {INT_MIN};
    dfs(root, sum);
    return sum[0];
}