// LeetCode #111: Minimum Depth of Binary Tree

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        int leftDepth = minDepth(root.left);
        int rightDepth = minDepth(root.right);
        
        if (leftDepth == 0) // The left subtree is empty.
            return 1 + rightDepth;
        if (rightDepth == 0) // The right subtree is empty.
            return 1 + leftDepth;
        return 1 + Math.min(leftDepth, rightDepth);
    }
}