public class Solution {
    public boolean canJump(int[] nums) {
        if (nums == null)
            return false;
            
        int maxstep = 0;
        for (int i = 0; i <= maxstep && i < nums.length; i++) {
            if (i + nums[i] > maxstep)
                maxstep = i + nums[i];
                
            if (maxstep >= nums.length - 1)
                return true;
        }
        return false;
    }
}