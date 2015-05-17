/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (root == NULL)
        return;
    if (root->left != NULL)
        root->left->next = root->right;
    if (root->right != NULL)
        root->right->next = root->next == NULL? NULL: root->next->left;
            
    connect(root->left);
    connect(root->right);
    return;
}