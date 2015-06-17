# LeetCode #40: Combination Sum II

'''
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
'''

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        res = []
        if candidates == None or len(candidates) == 0:
            return res
            
        candidates.sort()
        cur = []
        self.dfs(0, target, candidates, cur, res)
        return res
        
    def dfs(self, start, target, candidates, cur, res):
        if target == 0 and cur not in res:
            # Input:	[1], 1
            # Output:	[[]]
            # Expected:	[[1]]
            # tmp = cur + [] # Create a new list object based on current list.
            res.append(list(cur)) # http://stackoverflow.com/questions/2612802/how-to-clone-or-copy-a-list-in-python
            return
            
        for i in xrange(start, len(candidates)):
            if target >= candidates[i]:
                cur.append(candidates[i])
                self.dfs(i+1, target - candidates[i], candidates, cur, res)
                cur.pop()
        