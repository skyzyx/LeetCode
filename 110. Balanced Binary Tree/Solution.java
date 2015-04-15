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
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
            
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        int diff = Math.abs(leftHeight - rightHeight);
        
        if (diff <= 1 && isBalanced(root.left) && isBalanced(root.right))
            return true;
        return false;
    }
    
    private int getHeight(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }
}