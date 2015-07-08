// LeetCode #233: Number of Digit One

/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

public class Solution {
    public int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1? b: 0);
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
}

/*
public class Solution { // Time Limit Exceeded
    public int countDigitOne(int n) {
        int res = 0;
        while (n > 0) {
            res += countOne(n--);
        }
        return res;
    }
    
    private int countOne(int n) {
        int ans = 0;
        while (n > 0) {
            if (n % 10 == 1)
                ans++;
            n /= 10;
        }
        return ans;
    }
}
*/