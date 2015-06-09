// LeetCode #80: Remove Duplicates from Sorted Array II

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 3)
        return numsSize;
        
    int slow = 1;
    int fast = 2;
    while (fast < numsSize) {
        if (nums[fast] == nums[slow] && nums[fast] == nums[slow-1])
            fast++;
        else
            nums[++slow] = nums[fast++];
    }
    return slow+1;
}