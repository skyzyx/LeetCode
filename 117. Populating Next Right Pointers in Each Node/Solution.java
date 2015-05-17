/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;
            
        TreeLinkNode p = root.next;
        while (p != null) {
            if (p.left != null) {
                p = p.left;
                break;
            }
            
            if (p.right != null) {
                p = p.right;
                break;
            }
            
            p = p.next;
        }
        
        if (root.left != null)
            root.left.next = root.right == null? p: root.right;
            
        if (root.right != null)
            root.right.next = p;
            
        connect(root.right);
        connect(root.left);
    }
}