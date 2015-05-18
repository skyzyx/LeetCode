class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        if s == None or len(s) == 0:
            return ''
            
        maxLen = 0
        res = ''
        dp = [[False for i in xrange(len(s))] for j in xrange(len(s))]
        
        for i in xrange(len(s) - 1, -1, -1):
            for j in xrange(i, len(s)):
                if (s[i] == s[j]) and (j-i <= 1 or dp[i+1][j-1] == True):
                    dp[i][j] = True
                    if j-i+1 > maxLen:
                        maxLen = j-i+1
                        res = s[i:j]
        return res