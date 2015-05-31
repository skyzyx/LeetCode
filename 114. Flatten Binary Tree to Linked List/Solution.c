// LeetCode #114: Flatten Binary Tree to Linked List

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;
        
    if (root->left != NULL) {
        struct TreeNode* leftNode = root->left;
        struct TreeNode* rightNode = root->right;
        
        root->left = NULL;
        root->right = leftNode;
        
        struct TreeNode* p = root->right;
        while (p->right != NULL)
            p = p->right;
            
        p->right = leftNode;
    }
    
    flatten(root->right);
}