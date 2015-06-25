# LeetCode #228: Summary Ranges

'''
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
'''

class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        res = []
        if not nums or len(nums) == 0:
            return res
        
        i = 0
        while i < len(nums): # Did not work: for i in xrange(len(nums))
                             # Input: [0,1]
                             # Output: ["0->1","1"]
                             # Expected: ["0->1"]
            tmp = str(nums[i])
            countNum = 0
            
            while i+1 < len(nums) and nums[i+1] - nums[i] == 1:
                i += 1
                countNum += 1
            
            if countNum > 0:
                tmp = tmp + "->" + str(nums[i])
            
            res.append(tmp)
            i += 1
            
        return res;