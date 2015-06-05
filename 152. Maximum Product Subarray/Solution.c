// LeetCode #152: Maximum Product Subarray

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int max(int a, int b) {
    return a >= b? a: b;
}

int min(int a, int b) {
    return a < b? a: b;
}

int maxProduct(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0)
        return 0;
        
    int maxPro = nums[0];
    int maxTmp = nums[0];
    int minTmp = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        int a = maxTmp * nums[i];
        int b = minTmp * nums[i];
        
        maxTmp = max(max(a, b), nums[i]);
        minTmp = min(min(a, b), nums[i]);
        maxPro = max(maxTmp, maxPro);
    }
    return maxPro;
}