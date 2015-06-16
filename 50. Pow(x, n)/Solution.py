# LeetCode #50: Pow(x, n)

# Implement pow(x, n).

class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n == 0:
            return 1.0
        if n == 1:
            return x
        
        sign = n
        if n < 0:
            n = -n
            
        res = self.pow(x, n/2)
        if n % 2 == 0:
            res = res * res
        else:
            res = res * res * x
            
        return res if sign > 0 else 1/res
        