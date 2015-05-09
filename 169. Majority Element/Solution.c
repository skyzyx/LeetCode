int majorityElement(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0)
        return 0;
        
    int majIndex = 0;
    int majCount = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[majIndex]) // Not nums[i] == nums[i-1]
            majCount++;
        else
            majCount--;
            
        if (majCount == 0) {
            majIndex = i;
            majCount = 1;
        }
    }
    return nums[majIndex];
}