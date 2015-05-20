public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (nums == null || n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return Math.max(nums[0], nums[1]);
            
        return Math.max(houseRob(nums, 0, n-2), houseRob(nums, 1, n-1));
    }
    
    private int houseRob(int[] nums, int from, int to) {
        int even = 0;
        int odd = 0;
        for (int i = from; i <= to; i++) {
            if (i % 2 == 0)
                even = Math.max(even + nums[i], odd);
            else
                odd = Math.max(odd + nums[i], even);
        }
        return Math.max(even, odd);
    }
}