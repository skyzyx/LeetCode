public class Solution {
    public int jump(int[] nums) {
        if (nums == null)
            return -1;
            
        int currmax = 0;
        int lastmax = 0;
        int count = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (i > lastmax) {
                lastmax = currmax;
                count++;
            }
            
            currmax = Math.max(currmax, i + nums[i]);
        }
        return count;
    }
}