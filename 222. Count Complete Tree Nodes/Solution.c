// LeetCode #222: Count Complete Tree Nodes

/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
        
    int leftHeight = 0;
    struct TreeNode* p1 = root;
    while (p1 != NULL) {
        leftHeight++;
        p1 = p1->left;
    }
    
    int rightHeight = 0;
    struct TreeNode* p2 = root;
    while (p2 != NULL) {
        rightHeight++;
        p2 = p2->right;
    }
    
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}