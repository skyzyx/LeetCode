// LeetCode #199: Binary Tree Right Side View

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null)
            return res;
        
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        que.offer(root); // Not que.push(root);
        
        while (!que.isEmpty()) {
                int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode tmp = que.poll();
                if (i == 0)
                    res.add(tmp.val);
                if (tmp.right != null)
                    que.offer(tmp.right);
                if (tmp.left != null)
                    que.offer(tmp.left);
            }
        }
        return res;
    }
}