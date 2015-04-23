public class Solution {
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res = res << 1;
            res |= n & 1;
            n = n >> 1;
        }
        return res;
    }
}

/*
public class Solution {
    public int reverseBits(int n) {
        int res = 0;
        while (n > 0) {
            res = res << 1;
            res |= n & 1;
            n = n >> 1;
        }
        return res;
    }
}
Input:	           1 (00000000000000000000000000000001)
Output:	           1 (00000000000000000000000000000001)
Expected:	  2147483648 (10000000000000000000000000000000)
*/