# LeetCode #152: Maximum Product Subarray

'''
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
'''

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        maxPro = A[0];
        maxTmp = A[0];
        minTmp = A[0];
        
        for i in range(1, len(A)):
            a = maxTmp * A[i];
            b = minTmp * A[i];
            
            maxTmp = max(max(a, b), A[i]);
            minTmp = min(min(a, b), A[i]);
            maxPro = max(maxPro, maxTmp);
            
        return maxPro;
        