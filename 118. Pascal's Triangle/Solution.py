# LeetCode #118: Pascal's Triangle

'''
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
'''

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
        