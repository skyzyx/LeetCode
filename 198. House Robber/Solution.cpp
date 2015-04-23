class Solution {
public:
    int rob(vector<int> &num) {
        int size = num.size();
        if (size == 0)
            return 0;
            
        int dp[size+1] = {};
        dp[0] = 0;
        dp[1] = num[0];
        for (int i = 2; i <= size; i++)
            dp[i] = max(dp[i-1], dp[i-2] + num[i-1]);
        return dp[size];
    }
};