class Solution:
    # @param x, an integer
    # @return an integer
    def mySqrt(self, x):
        if x < 0:
            return -1
        if x == 0:
            return 0
            
        left = 0
        right = x / 2 + 1
        while left <= right:
            mid = (left + right) / 2
            if mid * mid == x:
                return mid
            elif mid * mid > x:
                right = mid - 1
            else :
                left = mid + 1
        return right
        