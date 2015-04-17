class Solution {
public:
    int singleNumber(int A[], int n) {
        int digits[32] = {};
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                digits[i] += (A[j] >> i) & 1;
            }
        }
        
        int res = 0;
        for (int k = 0; k < 32; k++) {
            res += (digits[k] % 3) << k;
        }
        return res;
    }
};