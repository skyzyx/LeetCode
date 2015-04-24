class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        res = []
        
        if numRows <= 0:
            return res
            
        cur = [1]
        res.append(cur)
        
        for i in range(0, numRows - 1):
            tmp = [1]
            for j in range(1, len(cur)):
                tmp.append(cur[j] + cur[j-1])
            tmp.append(1)
            
            res.append(tmp)
            
            cur = tmp
            
        return res
        