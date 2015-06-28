// LeetCode #84: Largest Rectangle in Histogram

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

// For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done.

public class Solution { // O(n)
    public int largestRectangleArea(int[] height) {
        if (height == null || height.length == 0)
            return 0;
        
        Stack<Integer> s = new Stack<Integer>();
        int maxArea = 0;
            
        int i = 0;
        while (i < height.length) {
            if (s.isEmpty() || height[i] > height[s.peek()]) {
                s.push(i);
                i++;
            } else {
                int curArea = height[s.pop()] * (s.isEmpty()? i: i - s.peek() - 1);
                maxArea = Math.max(maxArea, curArea);
            }
        }
        
        while (!s.isEmpty()) {
            int curArea = height[s.pop()] * (s.isEmpty()? i: i - s.peek() - 1);
            maxArea = Math.max(maxArea, curArea);
        }
        
        return maxArea;
    }
}

/*
public class Solution { // O(n^2), Time Limit Exceeded
    public int largestRectangleArea(int[] height) {
        if (height == null || height.length == 0)
            return 0;
            
        int maxArea = 0;
        for (int i = 0; i < height.length; i++) {
            int minHeight = height[i];
            for (int j = i; j < height.length; j++) {
                minHeight = Math.min(minHeight, height[j]);
                int curArea = (j-i+1) * minHeight;
                maxArea = Math.max(maxArea, curArea);
            }
        }
        return maxArea;
    }
}
*/