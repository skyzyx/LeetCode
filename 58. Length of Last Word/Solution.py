# LeetCode #58: Length of Last Word

'''
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
'''

class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        if len(s) == 0:
            return 0
            
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
            
        count = 0
        while i >= 0 and s[i] != ' ':
            i -= 1
            count += 1
            
        return count