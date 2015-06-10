// LeetCode #16: 3Sum Closest

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

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