# LeetCode #33: Search in Rotated Sorted Array

'''
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        if len(nums) == 0:
            return -1
            
        l = 0
        r = len(nums) - 1
        while l <= r:
            m = (l+r) / 2
            if nums[m] == target:
                return m
                
            if nums[l] < nums[m]:
                if target >= nums[l] and target <= nums[m]:
                    r = m-1
                else:
                    l = m+1
            elif nums[l] > nums[m]:
                if target >= nums[m] and target <= nums[r]:
                    l = m+1
                else:
                    r = m-1
            else:
                l += 1
        
        return -1
        