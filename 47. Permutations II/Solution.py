class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permuteUnique(self, nums):
        res = []
        if nums == None or len(nums) == 0:
            return res
            
        nums.sort()
        
        cur = []
        visited = [False] * len(nums)
        self.dfs(nums, cur, res, visited)
        return res
        
    def dfs(self, nums, cur, res, visited):
        if len(cur) == len(nums):
            res.append(list(cur))
            return
        
        for i in xrange(0, len(nums)):
            if (visited[i] == True) or (i > 0 and nums[i] == nums[i-1] and visited[i-1] == False):
                continue
            
            visited[i] = True
            cur.append(nums[i])
            self.dfs(nums, cur, res, visited)
            cur.pop()
            visited[i] = False
        