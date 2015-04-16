class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        count = 0
        i = 5
        while n >= i:
            count += n / i
            i *= 5
        return count
        