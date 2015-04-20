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