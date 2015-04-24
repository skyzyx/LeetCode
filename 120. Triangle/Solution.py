"""
class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        row = len(triangle)
        col = len(triangle[row-1])
        
        dp = []
        for item in triangle[row-1]:
            dp.append(item)
            
        for i in xrange(row-2, -1, -1):
            for j in xrange(0, len(triangle[i])):
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
                
        return dp[0]
"""