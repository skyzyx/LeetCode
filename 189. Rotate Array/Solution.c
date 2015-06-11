// LeetCode #189: Rotate Array

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

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