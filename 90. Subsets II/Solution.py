class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        res = [[]]
        for elem in sorted(S):
            res += [data + [elem] for data in res if data + [elem] not in res]
        return res
        