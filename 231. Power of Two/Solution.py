# LeetCode #231: Power of Two

# Given an integer, write a function to determine if it is a power of two.

class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        return n > 0 and (n & (n-1)) == 0