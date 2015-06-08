// LeetCode #27: Remove Element

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (A == NULL)
            return -1;
            
        if (n == 0)
            return 0;
            
        int slow = 0; 
        int fast = 0;
        while (fast < n) {
            if (A[fast] != elem)
                A[slow++] = A[fast];
            fast++;
        }
        return slow;
    }
};