# LeetCode #216: Combination Sum III

'''
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
'''

class Solution:
    # @param {integer} k
    # @param {integer} n
    # @return {integer[][]}
    def combinationSum3(self, k, n):
        res = []
        if k <= 0:
            return res
            
        cur = []
        self.dfs(k, n, 1, cur, res)
        return res
        
    def dfs(self, k, target, start, cur, res):
        if target == 0 and len(cur) == k:
            res.append(list(cur))
            return
        
        for i in xrange(start, 10):
            if target >= i:
                cur.append(i)
                self.dfs(k, target-i, i+1, cur, res)
                cur.pop()