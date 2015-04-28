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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List res = new ArrayList();
        if (root == null)
            return res;
            
        List<Integer> cur = new ArrayList<Integer>();
        dfs(root, cur, res, sum);
        return res;
    }
    
    private void dfs(TreeNode root, List<Integer> cur, List res, int sum) {
        if (root == null)
            return;
            
        if (root.left == null && root.right == null && root.val == sum) {
            cur.add(root.val);
            res.add(new ArrayList<Integer>(cur));
            /*
            Input:	{0,1,1}, 1
            Output:	[[0,1],[0,0,1]]
            Expected:	[[0,1],[0,1]]
            */
            // Without this line, an error will occur.
            cur.remove(cur.size() -1);
            return;
        }
        
        if (root.left != null) {
            cur.add(root.val);
            dfs(root.left, cur, res, sum - root.val);
            cur.remove(cur.size() - 1);
        }
        
        if (root.right != null) {
            cur.add(root.val);
            dfs(root.right, cur, res, sum - root.val);
            cur.remove(cur.size() - 1);
        }
    }
}