# LeetCode #44: Wildcard Matching

'''
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
'''

class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        i = 0
        j = 0
        star = -1
        mark = -1
        
        while i < len(s):
            if j < len(p) and (p[j] == '?' or p[j] == s[i]):
                i += 1
                j += 1
            elif j < len(p) and p[j] == '*':
                star = j
                j += 1
                mark = i
            elif star != -1:
                j = star + 1
                mark += 1
                i = mark
            else:
                return False
                
        while j < len(p) and p[j] == '*':
            j += 1
            
        return j == len(p)