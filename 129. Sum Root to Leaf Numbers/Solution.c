// LeetCode #129: Sum Root to Leaf Numbers

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
void getSum(struct TreeNode* root, int cur, int* res) {
    if (root == NULL)
        return;
        
    cur = cur * 10 + root->val;
    if (root ->left == NULL && root->right == NULL) {
        res[0] += cur;
        return;
    }
    
    getSum(root->left, cur, res);
    getSum(root->right, cur, res);
}
 
int sumNumbers(struct TreeNode *root) {
    if (root == NULL)
        return 0;
        
    int cur = 0;
    int res[1] = {0};
    getSum(root, cur, res);
    return res[0];
}

