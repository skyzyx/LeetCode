class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX; // NOT INT_MIN.
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                
                if (diff < min) {
                    min = diff;
                    res = sum;
                }
                
                if (target > sum)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};