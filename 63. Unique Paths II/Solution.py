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
        