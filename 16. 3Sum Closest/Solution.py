# LeetCode #16: 3Sum Closest

'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        minValue = 1 << 32
        res = 0
        
        nums.sort()
        
        for i in xrange(len(nums)):
            j = i+1
            k = len(nums)-1
            while j < k:
                threeSum = nums[i] + nums[j] + nums[k]
                diff = abs(target - threeSum)
                if diff < minValue:
                    minValue = diff
                    res = threeSum
                    
                if target > threeSum:
                    j += 1
                else:
                    k -= 1
        return res