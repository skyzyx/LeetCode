# LeetCode #81: Search in Rotated Sorted Array II

'''
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {boolean}
    def search(self, nums, target):
        if len(nums) == 0:
            return False
            
        l = 0
        r = len(nums) - 1
        while l <= r:
            m = (l+r) / 2
            if nums[m] == target:
                return True
                
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
        
        return False