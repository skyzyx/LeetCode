class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
            
        return max(self.houseRob(nums, 0, n-2), self.houseRob(nums, 1, n-1))
        
    def houseRob(self, nums, i, j):
        even = 0
        odd = 0
        for k in xrange(i, j+1):
            if k % 2 == 0:
                even = max(even + nums[k], odd)
            else:
                odd = max(odd + nums[k], even)
        return max(even, odd)