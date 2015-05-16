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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null)
            return null;
        int postLen = postorder.length - 1;
        int inLen = inorder.length - 1;
        return buildTree(inorder, 0, inLen, postorder, 0, postLen);
    }
    
    private TreeNode buildTree(int[] inorder, int inL, int inR, int[] postorder, int postL, int postR) {
        if (inL > inR)
            return null;
        TreeNode root = new TreeNode(postorder[postR]);
        int rootIndex = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (root.val == inorder[i]) {
                rootIndex = i;
                break;
            }
        }
        
        int size = rootIndex - inL;
        root.left = buildTree(inorder, inL, rootIndex - 1, postorder, postL, postL + size - 1);
        root.right = buildTree(inorder, rootIndex + 1, inR, postorder, postL + size, postR - 1);
        return root;
    }
}