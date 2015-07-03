# LeetCode #97: Interleaving String

'''
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
'''

class Solution:
    # @param {string} s1
    # @param {string} s2
    # @param {string} s3
    # @return {boolean}
    def isInterleave(self, s1, s2, s3):
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)
        
        if l1 + l2 != l3:
            return False
            
        dp = [[False for i in xrange(l2+1)] for j in xrange(l1+1)]
        dp[0][0] = True
        
        for i in xrange(1, l1+1):
            if s1[i-1] == s3[i-1]:
                dp[i][0] = True
            else:
                break
            
        for j in xrange(1, l2+1):
            if s2[j-1] == s3[j-1]:
                dp[0][j] = True
            else:
                break
            
        for i in xrange(1, l1+1):
            for j in xrange(1, l2+1):
                k = i+j-1
                if (dp[i-1][j] and s1[i-1] == s3[k]) or (dp[i][j-1] and s2[j-1] == s3[k]):
                    dp[i][j] = True
                    
        return dp[l1][l2]
        