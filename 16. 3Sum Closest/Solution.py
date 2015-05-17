class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        minValue = 1 << 32
        res = 0
        
        nums.sort()
        
        for i in xrange(len(nums)):
            j = i+1
            k = len(nums)-1
            while j < k:
                threeSum = nums[i] + nums[j] + nums[k]
                diff = abs(target - threeSum)
                if diff < minValue:
                    minValue = diff
                    res = threeSum
                    
                if target > threeSum:
                    j += 1
                else:
                    k -= 1
        return res