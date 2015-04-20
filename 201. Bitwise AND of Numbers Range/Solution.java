public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int pos = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            pos += 1;
        }
        return m << pos;
    }
}


/*
public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if (m > n)
            return -1;
        if (m == n)
            return m & m;
            
        int res = 1;
        while (m < n) {
            res &= m++;
        }
        return res;
    }
}
*/