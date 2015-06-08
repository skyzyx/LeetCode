// LeetCode #27: Remove Element

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    int fast = 0;
    while (fast < numsSize) {
        if (nums[fast] != val)
            nums[slow++] = nums[fast];
        fast++;
    }
    return slow;
}