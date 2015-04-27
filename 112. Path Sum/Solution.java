/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/* 
public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;
        if (root.left == null && root.right == null && root.val == sum)
            return true;
        return hasPathSum(root->left, sum - root.val) || hasPathSum(root->right, sum - root.val);
    }
}
*/

public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;
        if (root.left == null && root.right == null && root.val == sum)
            return true;
            
        Queue<TreeNode> node = new LinkedList<TreeNode>();
        Queue<Integer> value = new LinkedList<Integer>();
        
        node.offer(root);
        value.offer(root.val);
        
        while (!node.isEmpty()) { // Line 35: error: cannot find symbol: method empty()
            TreeNode foo = node.poll();
            int bar = value.poll();
            
            if (foo.left == null && foo.right == null && bar == sum)
                return true;
                
            if (foo.left != null) {
                node.offer(foo.left);
                value.offer(foo.left.val + bar);
            }
            
            if (foo.right != null) {
                node.offer(foo.right);
                value.offer(foo.right.val + bar);
            }
        }
        return false;    
    }
}