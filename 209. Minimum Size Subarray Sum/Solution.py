# LeetCode #209: Minimum Size Subarray Sum

'''
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
'''

class Solution:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        if nums == None or len(nums) == 0:
            return 0
            
        pre = 0
        cur = 0
        curSum = 0
        minLen = (1 << 31) - 1
        
        while cur < len(nums):
            while cur < len(nums) and curSum < s:
                curSum += nums[cur]
                cur += 1
                
            while curSum >= s:
                minLen = min(minLen, cur - pre)
                curSum -= nums[pre]
                pre += 1
                
        return minLen if minLen <= len(nums) else 0