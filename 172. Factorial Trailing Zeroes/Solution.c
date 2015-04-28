int trailingZeroes(int n) {
    long i = 5;
    int res = 0;
    while (n >= i) {
        res += n / i;
        i *= 5;
    }
    return res;
}