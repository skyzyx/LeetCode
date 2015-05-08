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