// LeetCode #117: Populating Next Right Pointers in Each Node II

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

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