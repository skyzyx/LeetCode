class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
            
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        
        while (i < j) {
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};