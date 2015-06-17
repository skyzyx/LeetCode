# LeetCode #45: Jump Game II

'''
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        if nums == None:
            return -1
            
        lastmax = 0
        currmax = 0
        steps = 0
        
        for i in xrange(0, len(nums)):
            if i > lastmax:
                lastmax = currmax
                steps += 1
                
            currmax = max(currmax, i + nums[i])
            
        return steps
        