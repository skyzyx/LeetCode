/*
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        String s = Integer.toBinaryString(n);
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1')
                count++;
        }
        return count;
    }
}
*/

/* // Last executed input:	  2147483648 (10000000000000000000000000000000)
public class Solution {
    public int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            if ((n & 1) == 1)
                res++;
            n >>= 1;
        }
        return res;
    }
}
*/

public class Solution {
    public int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n-1);
            res++;
        }
        return res;
    }
}
