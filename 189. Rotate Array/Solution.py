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