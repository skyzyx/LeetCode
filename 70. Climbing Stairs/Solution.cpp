// LeetCode #70: Climbing Stairs

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int dp[3] = {};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i%3] = dp[(i-1) % 3] + dp[(i-2) % 3];
        return dp[n%3];
    }
};