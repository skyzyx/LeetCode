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
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i <= inLen; i++)
            map.put(inorder[i], i);
    
        return dfs(map, preorder, 0, preLen, inorder, 0, inLen);
    }
    
    private TreeNode dfs(HashMap<Integer, Integer> map, int[] preorder, int preL, int preR, int[] inorder, int inL, int inR) {
        if (inL > inR || preL > preR)
            return null;
        
        TreeNode root = new TreeNode(preorder[preL]);
        int rootIndex = map.get(preorder[preL]);
        
        root.left = dfs(map, preorder, preL+1, rootIndex+preL-inL, inorder, inL, rootIndex-1);
        root.right = dfs(map, preorder, preL+rootIndex+1-inL, preR, inorder, rootIndex+1, inR);
        return root;
    }
}
