class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        int even = 0, odd = 0;
        
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0)
                even = max(even + nums[i], odd);
            else
                odd = max(odd + nums[i], even);
        }
        return max(even, odd);
    }
};

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
            
        int dp[size+1] = {0};
        dp[1] = nums[0];
        
        for (int i = 2; i <= size; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        return dp[size];
    }
};
*/