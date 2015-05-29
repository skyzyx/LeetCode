/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List res = new ArrayList();
        if (root == null)
            return res;
            
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        que.offer(root);
        
        while (!que.isEmpty()) {
            int size = que.size();
            List<Integer> tmp = new ArrayList<Integer>();
            
            for (int i = 0; i < size; i++) {
                TreeNode cur = que.poll();
                tmp.add(cur.val);
                
                if (cur.left != null)
                    que.offer(cur.left);
                if (cur.right != null)
                    que.offer(cur.right);
            }
            res.add(tmp);
        }
        return res;
    }
}