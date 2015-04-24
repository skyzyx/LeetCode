class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        hset = set()
        while n != 1 and n not in hset:
            hset.add(n)
            
            digit = 0
            sum = 0
            while n != 0:
                digit = n % 10
                sum += digit * digit
                n /= 10
            
            n = sum
        
        return n == 1