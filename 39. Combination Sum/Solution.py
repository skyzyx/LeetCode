class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):
        res = []
        if candidates == None or len(candidates) == 0:
            return res
            
        candidates.sort()    
        cur = []
        self.dfs(0, target, candidates, cur, res)
        return res
        
    def dfs(self, start, target, candidates, cur, res):
        if target == 0 and cur not in res:
            res.append(list(cur))
            return
        
        for i in xrange(start, len(candidates)):
            if target >= candidates[i]:
                cur.append(candidates[i])
                self.dfs(i, target - candidates[i], candidates, cur, res)
                cur.pop()
        