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