class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int lastmax = 0;
        int currmax = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > lastmax) {
                lastmax = currmax;
                count++;
            }
            
            currmax = max(currmax, i + nums[i]);
        }
        
        return count;
    }
};