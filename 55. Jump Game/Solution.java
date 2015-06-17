// LeetCode #55: Jump Game

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

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