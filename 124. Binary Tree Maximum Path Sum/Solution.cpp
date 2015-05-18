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
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum[1] = {INT_MIN};
        dfs(root, sum);
        return sum[0];
    }
    
private:
    int dfs(TreeNode* root, int sum[]) {
        if (root == NULL)
            return 0;
            
        int left = dfs(root->left, sum);
        int right = dfs(root->right, sum);
        
        int arch = left + right + root->val;
        int single = max(root->val, max(left, right) + root->val);
        
        sum[0] = max(sum[0], max(arch, single));
        return single;
    }
};