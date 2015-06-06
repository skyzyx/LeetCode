// LeetCode #213: House Robber II

/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

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