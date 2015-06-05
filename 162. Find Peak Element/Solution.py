# LeetCode #162: Find Peak Element

'''
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
'''

class Solution:
    def findPeakElement(self, nums):
        return self.findPeak(nums, 0, len(nums) - 1)
        
    def findPeak(self, nums, left, right):
        if left == right: # Only one element.
            return left
        
        """    
        Input:	[1,2]
        Output:	-1
        Expected:	1
        """
        if right - left == 1: # Two elements.
            return right if nums[right] > nums[left] else left
        
        mid = (left + right) / 2
        if nums[mid] >= nums[mid-1] and nums[mid] >= nums[mid+1]:
            return mid
        elif nums[mid] < nums[mid-1]:
            return self.findPeak(nums, left, mid-1)
        else:
            return self.findPeak(nums, mid+1, right)



"""
class Solution:
    # @param nums, an integer[]
    # @return an integer
    def findPeakElement(self, nums):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) / 2
            if (mid == 0 or nums[mid] >= nums[mid-1]) and (mid == len(nums) - 1 or nums[mid] > nums[mid + 1]):
                return mid
            elif mid > 0 and nums[mid] < nums[mid - 1]:
                right = mid - 1
            else:
                left = mid + 1
"""
        