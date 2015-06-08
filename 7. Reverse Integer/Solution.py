# LeetCode #7: Reverse Integer

'''
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
'''

class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        sign = 1
        if x < 0:
            sign = -1
            
        x = abs(x)    
        res = 0
        
        while x != 0:
            res = res * 10 + x % 10
            x /= 10
            
        res = res * sign
        if res > (1 << 31) - 1 or res < -(1 << 31): #if res > math.pow(2, 31) - 1 or res < math.pow(2, 31) * (-1):
            return 0
        else:
            return res