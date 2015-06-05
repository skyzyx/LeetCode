# LeetCode #168: Excel Sheet Column Title

'''
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
'''

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