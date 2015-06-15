// LeetCode #64: Unique Paths II

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        int[][] dp = new int[m][n];
        
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            else 
                break;
        }
        
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else 
                break;
        }
        
        for (int i = 1; i < m; i++) { 
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
}

// Solution 2.
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0 || obstacleGrid[0].length == 0)
            return 0;
        
        int[] res = new int[obstacleGrid[0].length];
        res[0] = 1;
        
        for (int i = 0; i < obstacleGrid.length; i++) {
            for (int j = 0; j < obstacleGrid[0].length; j++) {
                if (obstacleGrid[i][j] == 1) {
                    res[j] = 0;
                } else {
                    if (j > 0)
                        res[j] += res[j-1];
                }
            }
        }
        return res[obstacleGrid[0].length - 1];
    }
}