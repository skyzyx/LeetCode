class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        if len(s) == 0:
            return 0
            
        stack = []
        maxLen = 0
        lastValidIndex = -1
        
        for i in xrange(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if len(stack) == 0:
                    lastValidIndex = i
                else:
                    stack.pop()
                    if len(stack) == 0:
                        maxLen = max(maxLen, i - lastValidIndex)
                    else:
                        maxLen = max(maxLen, i - stack[len(stack) - 1])
        return maxLen