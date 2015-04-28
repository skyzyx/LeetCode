class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def uniquePaths(self, m, n):
        res = [[0 for i in xrange(n)] for j in xrange(m)]
        for i in xrange(n):
            res[0][i] = 1
        
        for i in xrange(m):
            res[i][0] = 1;
            
        for i in xrange(1, m):
            for j in xrange(1, n):
                res[i][j] = res[i-1][j] + res[i][j-1]
                
        return res[m-1][n-1]