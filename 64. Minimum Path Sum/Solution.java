// LeetCode #64: Minimum Path Sum

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        if (m == 0 || n == 0 || grid == null)
            return 0;
            
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
            
        for (int j = 1; j < m; j++)
            dp[j][0] = dp[j-1][0] + grid[j][0];
            
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
}