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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null)
            return res;
        
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        while (!s.isEmpty()) {
            TreeNode tmp = s.pop();
            res.add(tmp.val);
                
            if (tmp.right != null)
                s.push(tmp.right);
            if (tmp.left != null)
                s.push(tmp.left);
        }
        return res;
    }
}