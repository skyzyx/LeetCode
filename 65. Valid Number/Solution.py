# LeetCode #65: Valid Number

'''
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
'''

class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        i = 0
        n = len(s)
        
        while i < n and s[i] == ' ':
            i += 1
            
        if i < n and (s[i] == '+' or s[i] == '-'):
            i += 1
            
        isValid = False
        
        while i < n and s[i].isdigit():
            i += 1
            isValid = True
            
        if i < n and s[i] == '.':
            i += 1
            while i < n and s[i].isdigit():
                i += 1
                isValid = True
                
        if isValid and i < n and s[i] == 'e':
            i += 1
            isValid = False
            if i < n and (s[i] == '+' or s[i] == '-'):
                i += 1
                
            while i < n and s[i].isdigit():
                i += 1
                isValid = True
                
        while i < n and s[i] == ' ':
            i += 1
            
        return isValid and i == n
        