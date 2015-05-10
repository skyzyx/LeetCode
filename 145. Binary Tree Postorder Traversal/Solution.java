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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null)
            return res;
            
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        while (!s.empty()) {
            TreeNode tmp = s.pop();
            res.add(0, tmp.val);
            
            if (tmp.left != null)
                s.push(tmp.left);
            if (tmp.right != null)
                s.push(tmp.right);
        }
        return res;
    }
}