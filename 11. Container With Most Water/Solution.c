// LeetCode #11: Container With Most Water

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

int maxArea(int* height, int heightSize) {
    if (heightSize <= 1)
        return 0;
        
    int maxArea = 0;
    int i = 0;
    int j = heightSize - 1;
    
    while (i < j) {
        int h;
        if (height[i] > height[j])
            h = height[j];
        else
            h = height[i];
            
        int curArea = (j-i) * h;    
        if (curArea > maxArea)
            maxArea = curArea;
            
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxArea;
}