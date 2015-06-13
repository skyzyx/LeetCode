# LeetCode #77: Combinations

'''
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
'''

class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def combine(self, n, k):
        res = []
        if k <= 0:
            return res
            
        cur = []
        self.dfs(1, k, n, cur, res)
        return res
        
    def dfs(self, start, k, n, cur, res):
        if len(cur) == k:
            res.append(list(cur))
            return
        # Input:	1, 1
        # Output:	[]
        # Expected:	[[1]]
        for i in xrange(start, n+1): # NOT for i in xrange(start, n)
            cur.append(i)
            self.dfs(i+1, k, n, cur, res)
            cur.pop()