int reverse(int x) {
    int digit = 0;
    long res = 0;
    while (x != 0) {
        digit = x % 10;
        res = res * 10 + digit;
        x /= 10;
    }
    
    if (res > INT_MAX || res < INT_MIN)
        return 0;
    else
        return res;
}