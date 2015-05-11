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