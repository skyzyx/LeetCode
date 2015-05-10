class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permute(self, nums):
        res = []
        if nums == None or len(nums) == 0:
            return res
            
        cur = []
        self.dfs(nums, cur, res)
        return res
        
    def dfs(self, nums, cur, res):
        if len(cur) == len(nums):
            res.append(list(cur))
            return
        
        for i in xrange(0, len(nums)):
            if nums[i] not in cur:
                cur.append(nums[i])
                self.dfs(nums, cur, res)
                cur.pop()