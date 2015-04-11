class Solution:
    # @param num, a list of integer
    # @return an integer
    def rob(self, num):
        n = len(num);
        if (n == 0):
            return 0;
            
        dp = [0] * (n+1);
        dp[1] = num[0];
        for i in range(2, n+1):
            dp[i] = max(dp[i-1], dp[i-2] + num[i-1]);
        return dp[n];
        