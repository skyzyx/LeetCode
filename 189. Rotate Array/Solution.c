void reverse(int* nums, int l, int r) {
    while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        
        l++;
        r--;
    }
    return;
}

void rotate(int* nums, int numsSize, int k) {
    if (nums == NULL || numsSize == 0 || numsSize == 1 || k == 0)
        return;
        
    int order = k % numsSize;
    reverse(nums, 0, numsSize - order - 1);
    reverse(nums, numsSize - order, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
    return;
}