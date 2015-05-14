/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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
    private static ListNode node;
    
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)
            return null;
            
        node = head;
        int len = getLength(head);
        return dfs(0, len - 1);
    }
    
    private int getLength(ListNode head) {
        int res = 0;
        while (head != null) {
            res++;
            head = head.next;
        }
        return res;
    }
    
    private TreeNode dfs(int l, int r) {
        if (l > r)
            return null;
            
        int m = (l + r) / 2;
        TreeNode left = dfs(l, m-1);
        
        TreeNode root = new TreeNode(node.val);
        node = node.next;
        
        TreeNode right = dfs(m+1, r);
        
        root.left = left;
        root.right = right;
        return root;
    }
}