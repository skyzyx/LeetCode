int trap(int* height, int heightSize) {
    if (heightSize <= 1)
        return 0;
        
    int left[heightSize];
    int right[heightSize];
    
    int maxLeft = height[0];
    for (int i = 0; i < heightSize; i++) {
        left[i] = maxLeft;
        if (height[i] > maxLeft)
            maxLeft = height[i];
    }
    
    int water = 0;
    int maxRight = height[heightSize - 1];
    for (int i = heightSize-1; i >= 0; i--) {
        right[i] = maxRight;
        if (height[i] > maxRight)
            maxRight = height[i];
            
        int minHeight;
        if (left[i] < right[i])
            minHeight = left[i];
        else
            minHeight = right[i];
            
        if (height[i] < minHeight)
            water += minHeight - height[i];
    }
    return water;
}