// LeetCode #152: Maximum Product Subarray

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

public class Solution {
    public int maxProduct(int[] A) {
        int maxPro = A[0];
        int maxTmp = A[0];
        int minTmp = A[0];
        
        for (int i = 1; i < A.length; i++) {
            int a = maxTmp * A[i];
            int b = minTmp * A[i];
            
            maxTmp = Math.max(Math.max(a, b), A[i]);
            minTmp = Math.min(Math.min(a, b), A[i]);
            maxPro = Math.max(maxTmp, maxPro);
        }
        return maxPro;
    }
}