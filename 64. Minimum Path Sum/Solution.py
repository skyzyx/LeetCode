# LeetCode #64: Minimum Path Sum

'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
'''

class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
            
        m = len(grid)
        n = len(grid[0])
        
        dp = [[0 for x in xrange(n)] for x in xrange(m)]
        dp[0][0] = grid[0][0]
        
        for i in xrange(1, n):
            dp[0][i] = dp[0][i-1] + grid[0][i]
            
        for i in xrange(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
            
        for i in xrange(1, m):
            for j in xrange(1, n):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                
        return dp[m-1][n-1]