class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def firstMissingPositive(self, nums):
        i = 0
        n = len(nums)
        
        while i < n:
            if nums[i] != i+1 and nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i]-1]:
                self.swap(nums, i, nums[i]-1)
            else:
                i += 1
                
        for j in xrange(n):
            if nums[j] != j+1:
                return j+1
                
        return n+1
        
    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
            