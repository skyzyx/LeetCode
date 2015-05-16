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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null)
            return null;
        
        int preLen = preorder.length - 1;
        int inLen = inorder.length - 1;
        return buildTree(preorder, 0, preLen, inorder, 0, inLen);
    }
    
    private TreeNode buildTree(int[] preorder, int preL, int preR, int[] inorder, int inL, int inR) {
        if (inL > inR)
            return null;
        
        TreeNode root = new TreeNode(preorder[preL]);
        int rootIndex = 0;
        for (int k = 0; k < inorder.length; k++) {
            if (root.val == inorder[k]) {
                rootIndex = k;
                break;
            }
        }
        
        int size = rootIndex - inL;
        root.left = buildTree(preorder, preL+1, preL + size, inorder, inL, rootIndex-1);
        root.right = buildTree(preorder, preL + size + 1, preR, inorder, rootIndex+1, inR);
        return root;
    }
}
