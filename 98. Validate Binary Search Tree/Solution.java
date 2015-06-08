// LeetCode #98: Validate Binary Search Tree

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
        /*
        Input:	[2147483647]
        Output:	false
        Expected:	true
        */
    }
    
    private boolean dfs(TreeNode root, long min, long max) {
        if (root == null)
            return true;
        if (root.val <= min || root.val >= max)
            return false;
        return dfs(root.left, min, root.val) && dfs(root.right, root.val, max);
    }
}