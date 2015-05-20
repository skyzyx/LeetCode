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