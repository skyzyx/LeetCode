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