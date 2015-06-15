# LeetCode #64: Unique Paths II

'''
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
'''

class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
            
        dp = [[0 for i in xrange(n)] for j in xrange(m)]
        
        for i in xrange(n):
            if obstacleGrid[0][i] == 0:
                dp[0][i] = 1
            else:
                break
                    
        for i in xrange(m):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = 1
            else:
                break
                    
        for i in xrange(1, m):
            for j in xrange(1, n):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                else:
                    dp[i][j] = 0
                    
        return dp[m-1][n-1]
        