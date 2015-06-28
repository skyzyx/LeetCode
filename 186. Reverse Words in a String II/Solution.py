# LeetCode #186: Reverse Words in a String II

'''
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
'''

class Solution:
    # @param s, a list of 1 length strings, e.g., s = ['h','e','l','l','o']
    # @return nothing
    def reverseWords(self, s):
        self.reverseString(s, 0, len(s) - 1)
        
        i = 0
        while i < len(s):
            if s[i] != ' ':
                j = i
                while j < len(s) and s[j] != ' ':
                    j += 1
                
                self.reverseString(s, i, j-1)
                i = j
            i += 1
            
    def reverseString(self, s, i, j):
        while i < j:
            temp = s[i]
            s[i] = s[j]
            s[j] = temp
            
            i += 1
            j -= 1