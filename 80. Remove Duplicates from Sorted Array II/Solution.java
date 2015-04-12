public class Solution {
    public int removeDuplicates(int[] A) {
        if (A == null)
            return -1;
        if (A.length < 3)
            return A.length;
            
        int fast = 2;
        int slow = 1;
        while (fast < A.length) {
            if (A[fast] == A[slow] && A[fast] == A[slow-1]) {
                fast++;
            } else {
                A[++slow] = A[fast++];
            }
        }
        return slow+1;
    }
}