// LeetCode #198: House Robber

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

int max(int a, int b) {
    return a >= b? a: b;
}

int rob(int* nums, int numsSize) {
    int even = 0;
    int odd = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0)
            even = max(even + nums[i], odd);
        else
            odd = max(odd + nums[i], even);
    }
    return max(even, odd);
}

/*
int rob(int* nums, int numsSize) {
    int dp[numsSize+1];
    dp[0] = 0;
    dp[1] = nums[0];
    
    for (int i = 2; i <= numsSize; i++)
        if (dp[i-1] > dp[i-2] + nums[i-1])
            dp[i] = dp[i-1];
        else
            dp[i] = dp[i-2] + nums[i-1];
    return dp[numsSize];
}
*/