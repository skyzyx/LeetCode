# LeetCode #115: Distinct Subsequences

'''
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
'''
class Solution:
    def numDistinct(self, s, t):
        m = len(s)
        n = len(t)
        dp = [[0 for i in xrange(n+1)] for j in xrange(m+1)]
        
        for i in xrange(n+1):
            dp[0][i] = 0
        for i in xrange(m+1):
            dp[i][0] = 1
            
        for i in xrange(1, m+1):
            for j in xrange(1, n+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i-1][j]
                    
        return dp[m][n]


'''
class Solution: # Time Limit Exceeded
    # @param {string} s
    # @param {string} t
    # @return {integer}
    def numDistinct(self, s, t):
        if not s or not t:
            return 0
            
        if len(s) == 0:
            return 1 if len(t) == 0 else 0
            
        if len(t) == 0:
            return 1
            
        res = 0
        for i in xrange(len(s)):
            if s[i] == t[0]:
                res += self.numDistinct(s[i+1:], t[1:])
                
        return res;
'''