class Solution:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        if nums == None or len(nums) == 0:
            return 0
            
        pre = 0
        cur = 0
        curSum = 0
        minLen = (1 << 31) - 1
        
        while cur < len(nums):
            while cur < len(nums) and curSum < s:
                curSum += nums[cur]
                cur += 1
                
            while curSum >= s:
                minLen = min(minLen, cur - pre)
                curSum -= nums[pre]
                pre += 1
                
        return minLen if minLen <= len(nums) else 0