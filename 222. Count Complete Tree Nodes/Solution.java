// LeetCode #222: Count Complete Tree Nodes

/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
            
        int leftHeight = 0, rightHeight = 0;
        TreeNode p1 = root, p2 = root;
        
        while (p1 != null) {
            leftHeight++;
            p1 = p1.left;
        }
        
        while (p2 != null) {
            rightHeight++;
            p2 = p2.right;
        }
        
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        else
            return 1 + countNodes(root.left) + countNodes(root.right);
    }
}

/*
public class Solution { // Time Limit Exceeded
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
            
        int left = countNodes(root.left);
        int right = countNodes(root.right);
        return 1 + left + right;
    }
}
*/