# LeetCode #115: Distinct Subsequences

'''
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
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