// LeetCode #27: Remove Element

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

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