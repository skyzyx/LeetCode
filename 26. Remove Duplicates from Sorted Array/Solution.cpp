// LeetCode #26: Remove Duplicates from Sorted Array

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (A == NULL)
            return -1;
            
        if (n < 2)
            return n;
            
        int slow = 1;
        for (int fast = 1; fast < n; fast++) {
            if (A[fast] != A[fast-1]) {
                A[slow] = A[fast];
                slow++;
            }
        }
        return slow;
    }
};