class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        if nums == None:
            return -1
            
        lastmax = 0
        currmax = 0
        steps = 0
        
        for i in xrange(0, len(nums)):
            if i > lastmax:
                lastmax = currmax
                steps += 1
                
            currmax = max(currmax, i + nums[i])
            
        return steps
        