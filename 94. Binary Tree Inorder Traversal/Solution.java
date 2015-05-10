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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null)
            return res;
            
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode cur = root;
        
        while (cur != null || !s.isEmpty()) {
            if (cur != null) {
                s.push(cur);
                cur = cur.left;
            } else {
                TreeNode tmp = s.pop();
                res.add(tmp.val);
                cur = tmp.right;
            }
        }
        return res;
    }
}