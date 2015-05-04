class Solution:
    # @param {string} word1
    # @param {string} word2
    # @return {integer}
    def minDistance(self, word1, word2):
        m = len(word1)
        n = len(word2)
        
        dp = [[0 for i in xrange(n+1)] for j in xrange(m+1)]
        
        for i in xrange(m+1):
            dp[i][0] = i
        
        for j in xrange(n+1):
            dp[0][j] = j
            
        for i in xrange(1, m+1):
            for j in xrange(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1)
                    
        return dp[m][n]