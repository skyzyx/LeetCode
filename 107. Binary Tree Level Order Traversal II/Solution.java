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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List res = new ArrayList();
        if (root == null)
            return res;
            
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        que.offer(root);
        
        while (!que.isEmpty()) {
            int size = que.size();
            List<Integer> tmp = new ArrayList<Integer>();
            
            for (int i = 0; i < size; i++) {
                TreeNode foo = que.poll();
                tmp.add(foo.val);
                
                if (foo.left != null)
                    que.offer(foo.left);
                if (foo.right != null)
                    que.offer(foo.right);
            }
            res.add(0, tmp);
        }
        return res;
        
    }
}