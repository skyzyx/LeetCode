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