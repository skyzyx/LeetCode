// LeetCode #172: Factorial Trailing Zeroes

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

int trailingZeroes(int n) {
    long i = 5;
    int res = 0;
    while (n >= i) {
        res += n / i;
        i *= 5;
    }
    return res;
}