# LeetCode #198: House Robber

'''
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
'''

class Solution:
    def rob(self, nums):
        size = len(nums)
        even = 0
        odd = 0
        for i in xrange(size):
            if i % 2 == 0:
                even = max(even + nums[i], odd)
            else:
                odd = max(odd + nums[i], even)
        return max(even, odd)

'''
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if len(nums) == 0:
            return 0;
            
        dp = [0] * (len(nums) + 1)
        dp[1] = nums[0]
        
        for i in range(2, len(nums) + 1):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
            
        return dp[len(nums)]
'''
        