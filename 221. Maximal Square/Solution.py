# LeetCode #221: Maximal Square

'''
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
'''

class Solution:
    # @param {character[][]} matrix
    # @return {integer}
    def maximalSquare(self, matrix):
        if not matrix or len(matrix) == 0:
            return 0
            
        maxLen = 0
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                matrix[i][j] = int(matrix[i][j]) # character array to int array
                
                if i > 0 and j > 0 and matrix[i][j] == 1:
                    matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
                    
                
                maxLen = max(maxLen, matrix[i][j])
                
        return maxLen * maxLen # maxLen ** 2