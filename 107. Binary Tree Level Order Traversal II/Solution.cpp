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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
            
        queue<TreeNode*> que; // Not queue<TreeNode> que
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            
            for (int i = 0; i < size; i++) {
                TreeNode* foo = que.front(); // Be careful this line and the following line, those two lines can not be written as TreeNode* foo = que.pop(), que.pop() does NOT return anything in C++.
                que.pop(); // Not que.poll()
                
                tmp.push_back(foo->val);
                
                if (foo->left != NULL)
                    que.push(foo->left);
                if (foo->right != NULL)
                    que.push(foo->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};