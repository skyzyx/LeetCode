// LeetCode #226: Invert Binary Tree

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return root;
        return invert(root);
    }
    
    private TreeNode invert(TreeNode root) {
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        if (root.left != null)
            invert(root.left);
            
        if (root.right != null)
            invert(root.right);
        
        return root;
    }
}
/*
public class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return root;
        
        //TreeNode left = root.left;
        //TreeNode right = root.right;
        Input: [4,2,7,1,3,6,9]
        Output: [4,2,2,1,1,1,1]
        Expected: [4,7,2,9,6,3,1]
        
        root.right = invertTree(root.left);
        root.left = invertTree(root.right);
        return root;
    }
}
*/