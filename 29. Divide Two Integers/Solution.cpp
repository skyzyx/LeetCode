// LeetCode #29: Divide Two Integers

/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long foo = abs((long)dividend);
        long bar = abs((long)divisor);
        
        int res = 0;
        while (foo >= bar) {
            long tmp = bar;
            for (int i = 0; foo >= tmp; i++) {
                foo -= tmp;
                tmp <<= 1;
                res += 1 << i;
            }
        }
        
        return ((((dividend ^ divisor) >> 31) & 1) == 1)? -res: res;
    }
};