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