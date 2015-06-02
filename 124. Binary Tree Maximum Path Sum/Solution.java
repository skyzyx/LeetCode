// LeetCode #124: Binary Tree Maximum Path Sum

/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    public int maxPathSum(TreeNode root) {
        if (root == null)
            return 0;
        int[] sum = {Integer.MIN_VALUE};
        dfs(root, sum);
        return sum[0];
    }
    
    private int dfs(TreeNode root, int[] sum) {
        if (root == null)
            return 0;
            
        int leftSubTreeSum = dfs(root.left, sum);
        int rightSubTreeSum = dfs(root.right, sum);
        
        int arch = leftSubTreeSum + rightSubTreeSum + root.val;
        int single = Math.max(root.val, Math.max(leftSubTreeSum, rightSubTreeSum) + root.val);
        
        sum[0] = Math.max(sum[0], Math.max(arch, single));
        return single;
    }
}