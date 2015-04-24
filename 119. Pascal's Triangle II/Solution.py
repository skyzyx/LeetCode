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
        