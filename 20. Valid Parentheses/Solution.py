# LeetCode #20: Valid Parentheses

'''
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
'''

class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        if len(s) % 2 != 0:
            return False
            
        stack = []
        
        for i in xrange(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stack.append(s[i])
                continue
            
            if len(stack) > 0:
                top = stack[len(stack) - 1]
                if (top == '(' and s[i] == ')') or (top == '{' and s[i] == '}') or (top == '[' and s[i] == ']'):
                    stack.pop()
                else:
                    return False
                    
        return len(stack) == 0