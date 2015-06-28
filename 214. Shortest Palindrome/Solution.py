# LeetCode #214: Shortest Palindrome

'''
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
'''

class Solution:
    def shortestPalindrome(self, s):
        revs = s[::-1]
        l = s + "#" + revs
        
        p = [0] * len(l)
        for i in xrange(1, len(l)):
            j = p[i-1]
            while j > 0 and l[i] != l[j]:
                j = p[j-1]
            
            p[i] = j + (l[i] == l[j])
            
        return revs[:len(s) - p[-1]] + s


# Add extra character to the right of original string
# http://stackoverflow.com/questions/5617497/how-to-get-the-shortest-palindrome-of-a-string

'''
class Solution: # Time Limit Exceeded
    # @param {string} s
    # @return {string}
    def shortestPalindrome(self, s):
        if not s or len(s) <= 1:
            return s
            
        for i in xrange(len(s), -1, -1):
            currStr = s[i:len(s)][::-1] + s
            if self.isPalindrome(currStr):
                return currStr
            
        return s
        
    def isPalindrome(self, s):
        if len(s) <= 1:
            return True
            
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            
            i += 1
            j -= 1
            
        return True
'''