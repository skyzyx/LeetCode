// LeetCode #230: Kth Smallest Element in a BST

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
*/

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
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || k < 0) return 0;
        int leftNodes = findNodesSum(root->left);
        
        if (leftNodes + 1 == k)
            return root->val;
        else if (leftNodes + 1 > k)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - leftNodes - 1);
    }
    
private:
    int findNodesSum(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + findNodesSum(root->left) + findNodesSum(root->right);
    }
};