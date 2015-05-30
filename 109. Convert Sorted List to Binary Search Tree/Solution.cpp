// LeetCode #109: Convert Sorted List to Binary Search Tree

// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
            
        node = head;
        int len = getLength(head);
        return dfs(0, len-1);
    }

private:
    ListNode* node;
    
    int getLength(ListNode* head) {
        int res = 0;
        while (head != NULL) {
            res++;
            head = head->next;
        }
        return res;
    }
    
    TreeNode* dfs(int l, int r) {
        if (l > r)
            return NULL;
            
        int m = (l + r) / 2;
        TreeNode* left = dfs(l, m-1);
        
        TreeNode* root = new TreeNode(node->val);
        node = node->next;
        
        TreeNode* right = dfs(m+1, r);
        
        root->left = left;
        root->right = right;
        return root;
    }
};