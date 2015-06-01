# LeetCode #119: Pascal's Triangle II

'''
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
'''

class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        res = []
        if rowIndex < 0:
            return res
            
        res.append(1)
        for i in range(0, rowIndex):
            for j in range(len(res) - 1, 0, -1):
                res[j] += res[j-1]
            res.append(1)
            
        return res
        