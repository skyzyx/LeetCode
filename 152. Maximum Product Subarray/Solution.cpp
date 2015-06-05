// LeetCode #152: Maximum Product Subarray

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxPro = A[0];
        int maxTmp = A[0];
        int minTmp = A[0];
        
        for (int i = 1; i < n; i++) {
            int a = maxTmp * A[i];
            int b = minTmp * A[i];
            
            maxTmp = max(max(a, b), A[i]);
            minTmp = min(min(a, b), A[i]);
            maxPro = max(maxPro, maxTmp);
        }
        return maxPro;
    }
};