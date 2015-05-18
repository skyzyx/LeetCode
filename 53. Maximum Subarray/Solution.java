public class Solution {
    public int maxSubArray(int[] A) {
        int maxSum = A[0];
        int curSum = 0;
        for (int i = 0; i < A.length; i++) {
            curSum += A[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
}