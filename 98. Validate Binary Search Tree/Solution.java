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