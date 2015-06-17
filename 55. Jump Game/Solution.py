# LeetCode #55: Jump Game

'''
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
'''

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        if nums == None:
            return False
            
        maxdist = 0
        i = 0
        while i <= maxdist and i < len(nums):
            maxdist = max(maxdist, i + nums[i])
            if maxdist >= len(nums) - 1:
                return True
            i += 1
        return False
