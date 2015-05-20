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
        