# LeetCode #213: House Robber II

'''
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
            
        return max(self.houseRob(nums, 0, n-2), self.houseRob(nums, 1, n-1))
        
    def houseRob(self, nums, i, j):
        even = 0
        odd = 0
        for k in xrange(i, j+1):
            if k % 2 == 0:
                even = max(even + nums[k], odd)
            else:
                odd = max(odd + nums[k], even)
        return max(even, odd)