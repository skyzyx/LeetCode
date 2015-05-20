class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
            
        int pre = 0, cur = 0, sum = 0;
        int minLen = INT_MAX;
        
        while (cur < nums.size()) {
            while (cur < nums.size() && sum < s)
                sum += nums[cur++];
                
            while (sum >= s) {
                minLen = min(minLen, cur - pre);
                sum -= nums[pre++];
            }
        }
        
        return minLen > nums.size()? 0: minLen;
    }
};