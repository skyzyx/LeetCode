// LeetCode #99: Recover Binary Search Tree

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    private TreeNode node1 = null;
    private TreeNode node2 = null;
    
    public void recoverTree(TreeNode root) {
        inorderTraversal(root);
        int temp = node1.val;
        node1.val = node2.val;
        node2.val = temp;
    }
    
    private TreeNode prev = null;
    private void inorderTraversal(TreeNode root) {
        if (root == null)
            return;
            
        inorderTraversal(root.left);
        if (prev != null) {
            if (root.val <= prev.val) {
                if (node1 == null)
                    node1 = prev;
                node2 = root;
            }
        }
        prev = root;
        inorderTraversal(root.right);
    }
}