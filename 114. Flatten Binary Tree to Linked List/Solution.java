// LeetCode #114: Flatten Binary Tree to Linked List

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    public void flatten(TreeNode root) {
        if (root == null)
            return;
            
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        TreeNode pre = null;
        
        while (!s.isEmpty()) {
            TreeNode cur = s.pop();
            if (cur.right != null)
                s.push(cur.right);
                
            if (cur.left != null)
                s.push(cur.left);
                
            if (pre != null) {
                pre.left = null;
                pre.right = cur;
            }
            
            pre = cur;
        }
        return;
    }
}
 
/* 
public class Solution {
    public void flatten(TreeNode root) {
        if (root == null)
            return;
            
        if (root.left != null) {
            TreeNode leftNode = root.left;
            TreeNode rightNode = root.right;
            
            root.left = null;
            root.right = leftNode;
            
            TreeNode p = root.right;
            while (p.right != null)
                p = p.right;
                
            p.right = rightNode;
        }
        
        flatten(root.right);
    }
}
*/