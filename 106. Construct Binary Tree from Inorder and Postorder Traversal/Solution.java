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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null)
            return null;
            
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < inorder.length; i++)
            map.put(inorder[i], i);
        return dfs(map, inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
    
    private TreeNode dfs(HashMap<Integer, Integer> map, int[] inorder, int inL, int inR, int[] postorder, int posL, int posR) {
        if (inL > inR || posL > posR)
            return null;
            
        TreeNode root = new TreeNode(postorder[posR]);
        int rootIndex = map.get(postorder[posR]);
        
        root.left = dfs(map, inorder, inL, rootIndex - 1, postorder, posL, posL+rootIndex-inL-1);
        root.right = dfs(map, inorder, rootIndex+1, inR, postorder, posR+rootIndex-inR, posR-1);
        return root;
    }
}