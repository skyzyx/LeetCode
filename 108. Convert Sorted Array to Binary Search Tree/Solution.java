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
    public TreeNode sortedArrayToBST(int[] num) {
        return helper(num, 0, num.length - 1);
    }
    
    public TreeNode helper(int[] num, int left, int right) {
        if (left > right)
            return null;
            
        int middle = (left + right) / 2;
        TreeNode root = new TreeNode(num[middle]);
        root.left = helper(num, left, middle - 1);
        root.right = helper(num, middle + 1, right);
        return root;
    }
}