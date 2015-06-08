// LeetCode #209: Minimum Size Subarray Sum

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
            
        int left = 0, right = 0, sum = 0;
        int minLen = Integer.MAX_VALUE;
        
        while (right < nums.length) {
            while (right < nums.length && sum < s)
                sum += nums[right++];
            
            while (sum >= s) {
                minLen = Math.min(minLen, right - left);
                sum -= nums[left++];
            }
        }
        
        return minLen > nums.length? 0: minLen;
    }
}