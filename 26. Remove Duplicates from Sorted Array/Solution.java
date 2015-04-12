public class Solution {
    public int removeDuplicates(int[] A) {
        if (A == null)
            return -1;
        if (A.length < 2)
            return A.length;
            
        int slow = 1;
        for (int fast = 1; fast < A.length; fast++) {
            if (A[fast] != A[fast - 1]) {
                A[slow] = A[fast];
                slow++;
            }
        }
        return slow;
    }
}