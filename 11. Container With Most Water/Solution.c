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