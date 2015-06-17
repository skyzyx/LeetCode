// LeetCode #41: First Missing Positive

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

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