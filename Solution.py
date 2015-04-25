class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        if nums == None:
            return False
            
        maxdist = 0
        i = 0
        while i <= maxdist and i < len(nums):
            maxdist = max(maxdist, i + nums[i])
            if maxdist >= len(nums) - 1:
                return True
            i += 1
        return False
