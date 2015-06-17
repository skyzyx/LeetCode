// LeetCode #42: Trapping Rain Water

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

public class Solution {
    public int trap(int[] height) {
        if (height.length == 0)
            return 0;
            
        int m = height.length;
        int[] left = new int[m];
        int[] right = new int[m];
        
        int maxLeft = height[0];
        for (int i = 0; i < m; i++) {
            left[i] = maxLeft;
            if (height[i] > maxLeft)
                maxLeft = height[i];
        }
        
        int water = 0;
        int maxRight = height[m-1];
        for (int i = m-1; i >= 0; i--) {
            right[i] = maxRight;
            if (height[i] > maxRight)
                maxRight = height[i];
                
            if (height[i] < Math.min(left[i], right[i]))
                water += Math.min(left[i], right[i]) - height[i];
        }
        return water;
    }
}