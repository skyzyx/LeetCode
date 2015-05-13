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