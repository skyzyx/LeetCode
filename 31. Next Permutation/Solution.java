// LeetCode #31: Next Permutation

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

public class Solution {
    public void nextPermutation(int[] nums) {
        int i = 0, j = 0;
        
        for (i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1])
                break;
        }
        
        for (j = nums.length - 1; j > i && i >= 0; j--) {
            if (nums[j] > nums[i])
                break;
        }

        
        if (i >= 0)
            swap(nums, i, j);
        
        int start = i+1;
        int end = nums.length - 1;
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}