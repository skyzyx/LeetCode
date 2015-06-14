# LeetCode #78: Subsets

'''
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
'''

class Solution:
    def subsets(self, S):
        res = [[]]
        for elem in sorted(S):
            res = res + [foo + [elem] for foo in res]
        return res

"""
class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        res = [[]]
        S.sort()
        for i in xrange(len(S)):
            length = len(res)
            for j in xrange(length):
                tmp = res[j] + [S[i]]
                res.append(tmp)
        return res
"""