// LeetCode #108: Convert Sorted Array to Binary Search Tree

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    public TreeNode sortedArrayToBST(int[] num) {
        return dfs(num, 0, num.length - 1);
    }
    
    public TreeNode dfs(int[] num, int left, int right) {
        if (left > right)
            return null;
            
        int middle = (left + right) / 2;
        TreeNode root = new TreeNode(num[middle]);
        root.left = dfs(num, left, middle - 1);
        root.right = dfs(num, middle + 1, right);
        return root;
    }
}