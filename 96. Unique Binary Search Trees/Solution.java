// LeetCode #96: Unique Binary Search Trees

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

public class Solution { // Dynamic Programming
    public int numTrees(int n) {
        if (n <= 0)
            return 0;
            
        int[] dp = new int[n+1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
}

/*
public class Solution { // Recursion
    public int numTrees(int n) {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1)
            return 1;
            
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += numTrees(i-1) * numTrees(n-i);
        }
        return res;
    }
}
*/