// LeetCode #209: Minimum Size Subarray Sum

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

int min(int a, int b) {
    return a < b? a: b;
}

int minSubArrayLen(int s, int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
        
    int pre = 0, cur = 0, sum = 0;
    int minLen = INT_MAX;
    
    while (cur < numsSize) {
        while (cur < numsSize && sum < s)
            sum += nums[cur++];
            
        while (sum >= s) {
            minLen = min(minLen, cur - pre);
            sum -= nums[pre++];
        }
    }
    
    return minLen > numsSize? 0: minLen;
}