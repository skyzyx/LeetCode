int searchInsert(int A[], int n, int target) {
    if (A == NULL)
        return -1;
        
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}