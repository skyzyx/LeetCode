# LeetCode #53: Maximum Subarray

'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
'''

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