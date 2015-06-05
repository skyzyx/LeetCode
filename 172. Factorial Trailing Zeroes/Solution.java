// LeetCode #172: Factorial Trailing Zeroes

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

public class Solution {
    public int trailingZeroes(int n) {
        int count = 0;
        // http://www.danielbit.com/blog/puzzle/leetcode/leetcode-factorial-trailing-zeroes
        // NOT for (int = 5; n / i > 0; i *= 5)
        for (long i = 5; n / i > 0; i *= 5) { // java.lang.ArithmeticException: / by zero
            count += n / i;
        }
        return count;
    }
}