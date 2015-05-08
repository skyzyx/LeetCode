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
        