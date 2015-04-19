class Solution:
    def climbStairs(self, n):
        dp = [1, 1];
        while (len(dp) < n+1):
            dp.append(dp[-1] + dp[-2]);
        return dp[n];

'''
class Solution:
    def climbStairs(self, n):
        dp = [0] * (n+1);
        dp[0] = 1;
        dp[1] = 1;
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
'''

'''
class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        dp = [0] * 3;
        dp[0] = 1;
        dp[1] = 1;
        for i in range(2, n+1):
            dp[i%3] = dp[(i-1) % 3] + dp[(i-2) % 3];
        return dp[n%3];
'''    