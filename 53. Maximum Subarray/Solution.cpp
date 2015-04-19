class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0];
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += A[i];
            if (cur > max)
                max = cur;
            if (cur < 0)
                cur = 0;
        }
        return max;
    }
};