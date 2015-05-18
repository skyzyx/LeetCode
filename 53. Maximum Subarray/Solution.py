class Solution:
    def maxSubArray(self, A):
        maxSum = A[0];
        curSum = 0;
        for i in range (0, len(A)):
            curSum += A[i];
            if (curSum > maxSum):
                maxSum = curSum;
            if (curSum < 0):
                curSum = 0;
        return maxSum;

'''
class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        maxSum = A[0];
        cur = 0;
        
        for element in A:
            cur += element;
            if (cur > maxSum):
                maxSum = cur;
                
            if (cur < 0):
                cur = 0;
        
        return maxSum;
'''