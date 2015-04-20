class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        pos = 0
        while m != n:
            m >>= 1
            n >>= 1
            pos += 1
        return m << pos
        