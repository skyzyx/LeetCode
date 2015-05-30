// LeetCode #107: Binary Tree Level Order Traversal II

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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