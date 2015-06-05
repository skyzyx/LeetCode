# LeetCode #172: Factorial Trailing Zeroes

'''
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
'''

class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        count = 0
        i = 5
        while n >= i:
            count += n / i
            i *= 5
        return count
        