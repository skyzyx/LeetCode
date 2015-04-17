class Solution:
    # @param n, an integer
    # @return an integer[]
    def grayCode(self, n):
        res = []
        if n == 0:
            res.append(0)
            return res
        
        preRes = self.grayCode(n-1) # NameError: global name 'grayCode' is not defined
        res.extend(preRes)
        
        for item in preRes[::-1]: # Traverse a list backwards # for item in reversed(preRes)
            res.append(item + pow(2, n-1))
            
        return res
        