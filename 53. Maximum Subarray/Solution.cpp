// LeetCode #53: Maximum Subarray

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
};