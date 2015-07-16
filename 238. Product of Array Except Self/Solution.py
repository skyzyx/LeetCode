# LeetCode #238: Product of Array Except Self

'''
Given an array of n integers where n > 1, nums, return an array output such that 
output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not 
count as extra space for the purpose of space complexity analysis.)
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        if nums is None or len(nums) < 2:
            return nums
            
        n = len(nums)
        res = [0 for i in xrange(n)]
        res[0] = 1
        
        for i in xrange(1, n):
            res[i] = res[i-1] * nums[i-1]
            
        right = 1
        for i in xrange(n-1, -1, -1):
            res[i] *= right
            right *= nums[i]
            
        return res