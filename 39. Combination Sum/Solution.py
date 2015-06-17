# LeetCode #39: Combination Sum

'''
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
'''

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
        