# LeetCode #89: Gray Code

'''
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
'''

class Solution:
    def grayCode(self, n):
        res = []
        if n < 0:
            return res
        
        res.append(0)
        for i in xrange(1, n+1):
            res = res + [(1 << (i-1)) + item for item in reversed(res)]
        return res

''' 
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
'''