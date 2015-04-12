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