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
        
    struct TreeLinkNode* p = root->next;
    while (p != NULL) {
        if (p->left != NULL) {
            p = p->left;
            break;
        }
        
        if (p->right != NULL) {
            p = p->right;
            break;
        }
        
        p = p->next;
    }
    
    if (root->left != NULL)
        root->left->next = root->right == NULL? p: root->right;
        
    if (root->right != NULL)
        root->right->next = p;
        
    connect(root->right);
    connect(root->left);
}