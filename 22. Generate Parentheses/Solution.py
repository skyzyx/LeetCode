# LeetCode #22: Generate Parentheses

'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
'''

class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        res = []
        if n <= 0:
            return res
            
        res.append("()")
        
        for i in xrange(1, n):
            cur = []
            for elem in res:
                for j in xrange(0, len(elem) + 1):
                    tmp = elem[0:j] + "()" + elem[j:]
                    if tmp not in cur:
                        cur.append(tmp)
            res = list(cur)
        return res