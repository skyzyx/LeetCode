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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List res = new ArrayList();
        if (root == null)
            return res;
            
        boolean normal_dir = true;
        
        Stack<TreeNode> curr = new Stack<TreeNode>();
        curr.push(root);
        
        while (!curr.isEmpty()) {
            int size = curr.size();
            List<Integer> tmp = new ArrayList<Integer>();
            Stack<TreeNode> next = new Stack<TreeNode>();
            
            for (int i = 0; i < size; i++) {
                TreeNode foo = curr.pop();
                tmp.add(foo.val);
                
                if (normal_dir) {
                    if (foo.left != null)
                        next.push(foo.left);
                    if (foo.right != null)
                        next.push(foo.right);
                } else {
                    if (foo.right != null)
                        next.push(foo.right);
                    if (foo.left != null)
                        next.push(foo.left);
                }
            }
            res.add(tmp);
            normal_dir = !normal_dir;
            curr = next;
        }
        return res;
    }
}