# LeetCode #18: 4Sum

'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[][]}
    def fourSum(self, nums, target):
        res = []
        nums.sort()
        
        for i in xrange(0, len(nums)):
            for j in xrange(i+1, len(nums)):
                l = j + 1
                r = len(nums) - 1
                remain = target - nums[i] - nums[j]
                
                while l < r:
                    if remain == nums[l] + nums[r]:
                        cur = []
                        cur.append(nums[i])
                        cur.append(nums[j])
                        cur.append(nums[l])
                        cur.append(nums[r])
                    
                        if cur not in res:
                            res.append(cur)
                        
                        l += 1
                        r -= 1
                    elif remain > nums[l] + nums[r]:
                        l += 1
                    else:
                        r -= 1
        return res