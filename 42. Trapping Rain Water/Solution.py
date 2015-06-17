# LeetCode #42: Trapping Rain Water

'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
'''

class Solution:
    # @param {integer[]} height
    # @return {integer}
    def trap(self, height):
        if len(height) == 0:
            return 0
            
        left = [0] * len(height)
        right = [0] * len(height)
        
        leftMax = height[0]
        for i in range(len(height)):
            left[i] = leftMax
            if height[i] > leftMax:
                leftMax = height[i]
                
        water = 0
        rightMax = height[len(height) - 1]
        for i in xrange(len(height)-1, -1, -1):
            right[i] = rightMax
            if height[i] > rightMax:
                rightMax = height[i]
                
            if height[i] < min(left[i], right[i]):
                water += min(left[i], right[i]) - height[i]
                
        return water;
        