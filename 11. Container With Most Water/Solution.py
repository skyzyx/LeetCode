class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        if len(height) <= 1:
            return 0
            
        maxArea = 0
        i = 0
        j = len(height) - 1
        
        while i < j:
            maxArea = max(maxArea, (j-i) * min(height[i], height[j]))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return maxArea