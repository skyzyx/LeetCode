// LeetCode #137: Single Number II

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

public class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int j = 0; j < nums.length; j++) {
                bitSum += (nums[j] >> i) & 1;
            }
            
            res = res | ((bitSum % 3) << i);
        }
        return res;
    }
}