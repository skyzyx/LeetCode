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
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode p = root;
 
        while(p != null || !stack.empty()){
 
            if(p.right != null){
                stack.push(p.right);
            }
 
            if(p.left != null){
                p.right = p.left;
                p.left = null;
            }else if(!stack.empty()){
                TreeNode temp = stack.pop();
                p.right=temp;
            }
 
            p = p.right;
        }
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