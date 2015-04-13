public class Solution {
    public int removeElement(int[] A, int elem) {
        if (A == null)
            return -1;
        if (A.length == 0)
            return 0;
            
        int slow = 0;
        int fast = 0;
        while (fast < A.length) {
            if (A[fast] != elem) 
                A[slow++] = A[fast];
            fast++;
        }
        return slow;
    }
}