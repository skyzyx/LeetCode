class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int pos = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            pos += 1;
        }
        return m << pos;
    }
};