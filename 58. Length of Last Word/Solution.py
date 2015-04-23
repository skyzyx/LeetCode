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