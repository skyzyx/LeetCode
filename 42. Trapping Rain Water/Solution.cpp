// LeetCode #42: Trapping Rain Water

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
            
        int m = height.size();
        int left[m];
        int right[m];
        
        int maxLeft = height[0];
        for (int i = 0; i < m; i++) {
            left[i] = maxLeft;
            if (height[i] > maxLeft)
                maxLeft = height[i];
        }
        
        int water = 0;
        int maxRight = height[m-1];
        for (int i = m-1; i >=0; i--) {
            right[i] = maxRight;
            if (height[i] > maxRight)
                maxRight = height[i];
                
            if (height[i] < min(left[i], right[i])) {
                water += min(left[i], right[i]) - height[i];
            }
        }
        return water;
    }
};