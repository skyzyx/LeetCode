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