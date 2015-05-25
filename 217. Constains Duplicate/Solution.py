class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        if len(nums) < 2:
            return False
            
        nums.sort()
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1]:
                return True
                
        return False