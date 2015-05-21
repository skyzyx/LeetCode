class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        res = ""
        while n > 0:
            n -= 1
            letter = chr((n % 26) + ord('A'))
            res = letter + res
            n /= 26
        return res