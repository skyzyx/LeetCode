public class Solution {
    public int maxSubArray(int[] A) {
        int max = A[0];
        int cur = 0;
        for (int i = 0; i < A.length; i++) {
            cur += A[i];
            if (cur > max)
                max = cur;
            if (cur < 0)
                cur = 0;
        }
        return max;
    }
}