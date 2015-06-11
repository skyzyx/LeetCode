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

public class Solution {
    public void rotate(int[] nums, int k) {
        int order = k % nums.length;
        int size = nums.length;
        
        reverse(nums, 0, size - order - 1);
        reverse(nums, size - order, size - 1);
        reverse(nums, 0, size - 1);
        return;
    }
    
    private static void reverse(int[] A, int left, int right) {
        while (left < right) {
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            
            left++;
            right--;
        }
    }
}