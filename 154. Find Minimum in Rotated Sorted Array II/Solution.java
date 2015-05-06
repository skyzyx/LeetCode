public class Solution {
    public int findMin(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
            
        int l = 0;
        int r = nums.length - 1;
        int min = nums[0];
        
        /*
        Input:	[1,1,2,0,0,1]
        Output:	1
        Expected: 0
        */
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (nums[l] < nums[m]) {
                min = Math.min(min, nums[l]);
                l = m + 1;
            } else if (nums[l] > nums[m]) {
                min = Math.min(min, nums[m]);
                r = m - 1;
            } else { // Duplicates.
                l++;
            }
        }
        
        min = Math.min(min, Math.min(nums[l], nums[r]));
        return min;
    }
}

