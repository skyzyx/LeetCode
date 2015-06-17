# LeetCode #3: Longest Substring Without Repeating Characters

# Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

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