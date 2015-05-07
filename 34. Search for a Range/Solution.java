public class Solution {
    public int[] searchRange(int[] nums, int target) {
        /*
        NOT int[] res = {-1, -1}
        Input:	[1], 1
        Output:	[-1,0]
        Expected:	[0,0]
        */
        
        int[] res = {Integer.MAX_VALUE, Integer.MIN_VALUE};
        binarySearch(nums, target, res, 0, nums.length - 1);
        if (res[0] == Integer.MAX_VALUE)
            res[0] = -1;
        if (res[1] == Integer.MIN_VALUE)
            res[1] = -1;
        return res;
    }
    
    private void binarySearch(int[] nums, int target, int[] res, int l, int r) {
        if (l > r)
            return;
            
        int m = (l + r) / 2;
        if (nums[m] == target) {
            res[0] = Math.min(res[0], m);
            res[1] = Math.max(res[1], m);
            binarySearch(nums, target, res, l, m-1);
            binarySearch(nums, target, res, m+1, r);
        } else if (nums[m] > target) {
            binarySearch(nums, target, res, l, m-1);
        } else {
            binarySearch(nums, target, res, m+1, r);
        }
    }
}