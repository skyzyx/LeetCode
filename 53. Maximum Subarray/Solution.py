class Solution:
    def maxSubArray(self, A):
        max = A[0];
        cur = 0;
        for i in range (0, len(A)):
            cur += A[i];
            if (cur > max):
                max = cur;
            if (cur < 0):
                cur = 0;
        return max;

'''
class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        max = A[0];
        cur = 0;
        
        for element in A:
            cur += element;
            if (cur > max):
                max = cur;
                
            if (cur < 0):
                cur = 0;
        
        return max;
'''