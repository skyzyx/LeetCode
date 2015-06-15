// LeetCode #62: Unique Paths

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

public class Solution {
    public int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
            
        int[][] res = new int[m][n];
        for (int i = 0; i < n; i++)
            res[0][i] = 1;
        
        for (int j = 0; j < m; j++)
            res[j][0] = 1;
            
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        
        return res[m-1][n-1];
    }
}