/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* dfs(int* nums, int l, int r) {
    if (l > r)
        return NULL;
        
    int m = (l + r) / 2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode*));
    root->val = nums[m];
    root->left = dfs(nums, l, m-1);
    root->right = dfs(nums, m+1, r);
    return root;
} 
 
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    return dfs(nums, 0, numsSize - 1);
}