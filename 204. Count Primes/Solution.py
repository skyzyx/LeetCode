class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 1:
            return 0
            
        isPrime = [True] * n
        isPrime[0] = isPrime[1] = False
        
        i = 2
        while i * i < n:
            tmp = i * i
            if isPrime[tmp]:
                while tmp < n:
                    isPrime[tmp] = False
                    tmp += i
            i += 1
            
        return sum(isPrime)