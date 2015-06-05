// LeetCode #172: Factorial Trailing Zeroes

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (long i = 5; n / i > 0; i *= 5)
            count += n / i;
        return count;
    }
};