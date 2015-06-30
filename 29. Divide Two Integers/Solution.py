# LeetCode #29: Divide Two Integers

'''
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
'''

class Solution:
    # @param {integer} dividend
    # @param {integer} divisor
    # @return {integer}
    def divide(self, dividend, divisor):
        sign = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else -1 
        foo = abs(dividend)
        bar = abs(divisor)
        
        res = 0
        while foo >= bar:
            i = 0
            tmp = bar
            while foo >= tmp:
                res += 1 << i
                foo = foo - tmp
                tmp = tmp << 1
                i += 1
            
        return min(max(-2147483648, res * sign), 2147483647)