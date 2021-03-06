# LeetCode #137: Single Number II

'''
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
'''

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        digits = [0] * 32
        for i in range(0, 32):
            for j in range(0, len(A)):
                digits[i] += (A[j] >> i) & 1
            
        res = 0    
        for k in range(0, 32):
            res += (digits[k] % 3) << k
            
        return res