// LeetCode #137: Single Number II

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int* nums, int numsSize) {
    int res = 0;
    
    for (int i = 0; i < 32; i++) {
        int bitSum = 0;
        for (int j = 0; j < numsSize; j++) {
            bitSum += ((nums[j] >> i) & 1);
        }
        
        res = res | ((bitSum % 3) << i);
    }
    return res;
}

// Input:	[2,2,3,2]
// Output:	0
// Expected:	3
/*
int singleNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
        
    return sum % 3;
}
*/