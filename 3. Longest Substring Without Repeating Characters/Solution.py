class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        if len(s) <= 1:
            return len(s)
            
        prev = 0
        maxLen = 0
        visited = [False] * 256
        
        for i in xrange(len(s)):
            if visited[ord(s[i])] == False: # list indices must be integers, not unicode
                visited[ord(s[i])]= True
            else:
                while s[i] != s[prev]:
                    visited[ord(s[prev])] = False
                    prev += 1
                prev += 1
            maxLen = max(maxLen, i - prev + 1)
        return maxLen