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

