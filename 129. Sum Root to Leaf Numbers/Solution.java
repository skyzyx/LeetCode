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
    public int sumNumbers(TreeNode root) {
        int[] res = {0};
        int cur = 0;
        getSum(root, res, cur);
        return res[0];
    }
    
    public void getSum(TreeNode root, int[] res, int cur) {
        if (root == null)
            return;
        
        cur = cur * 10 + root.val;
        if (root.left == null && root.right == null) {
            res[0] += cur;
            return;
        }
        
        getSum(root.left, res, cur);
        getSum(root.right, res, cur);
    }
}