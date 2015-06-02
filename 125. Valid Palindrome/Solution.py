# LeetCode #125: Valid Palindrome

'''
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
'''

class Solution:
    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        i = 0;
        j = len(s) - 1
        
        while i < j:
            if not s[i].isalnum(): # Not isalnum(s[i])
                i += 1
                continue
            
            if not s[j].isalnum():
                j -= 1
                continue
            
            if s[i].lower() != s[j].lower(): # NOt like this, if lower(s[i]) != lower(s[j]):
                return False
                
            i += 1
            j -= 1
        
        return True