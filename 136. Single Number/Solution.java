public class Solution {
    public int singleNumber(int[] A) {
        if (A == null || A.length == 0)
            return -1;

        if (A.length == 1)
            return A[0];
        
        int res = A[0];
        for (int i = 1; i < A.length; i++) {
            res ^= A[i];
        }
        
        return res;
    }
}