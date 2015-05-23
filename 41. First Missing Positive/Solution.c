void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    while (i < numsSize) {
        if (nums[i] != i+1 && nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
            swap(nums, i, nums[i]-1);
        else
            i++;
    }
    
    for (int j = 0; j < numsSize; j++)
        if (nums[j] != j+1)
            return j+1;
            
    return numsSize+1;
}