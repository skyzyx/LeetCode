// LeetCode #29: Divide Two Integers

/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

public class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;
        
        long foo = Math.abs((long)dividend); // Do not write like: long foo = Math.abs(dividend), otherwise it will overflow.
        long bar = Math.abs((long)divisor);
        
        /*
        Input:  -2147483648, -1
        Output: -2147483648
        Expected:   2147483647
        */
        
        int res = 0;
        
        while (foo >= bar) {
            long tmp = bar;
            for (int i = 0; foo >= tmp; i++) {
                foo = foo - tmp;
                tmp = tmp << 1;
                res += 1 << i;
            }
        }
        
        return ((((dividend ^ divisor) >> 31) & 1) == 1)? -res: res; // Without & 1, it won't work.
    }
}