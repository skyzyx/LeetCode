// LeetCode #80: Remove Duplicates from Sorted Array II

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (A == NULL)
            return -1;
        if (n < 3)
            return n;
            
        int slow = 1;
        int fast = 2;
        while (fast < n) {
            if (A[fast] == A[slow] && A[fast] == A[slow - 1])
                fast++;
            else
                A[++slow] = A[fast++];
        }
        return slow + 1;
    }
};