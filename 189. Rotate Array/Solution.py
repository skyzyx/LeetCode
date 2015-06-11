# LeetCode #189: Rotate Array

'''
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {void} Do not return anything, modify nums in-place instead.
    def rotate(self, nums, k):
        if len(nums) == 0 or len(nums) == 1 or k == 0:
            return
        
        n = len(nums)
        order = k % n
        
        self.reverse(nums, 0, n - order - 1)
        self.reverse(nums, n - order, n - 1)
        self.reverse(nums, 0, n - 1)
        return
    
    def reverse(self, nums, l, r):
        while l < r:
            tmp = nums[l]
            nums[l] = nums[r]
            nums[r] = tmp
            
            l += 1
            r -= 1
        return